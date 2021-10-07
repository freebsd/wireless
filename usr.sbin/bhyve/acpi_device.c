/*-
 * SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * Copyright (c) 2021 Beckhoff Automation GmbH & Co. KG
 * Author: Corvin Köhne <c.koehne@beckhoff.com>
 */

#include <sys/param.h>
#include <sys/queue.h>

#include <machine/vmm.h>

#include <assert.h>
#include <err.h>
#include <errno.h>
#include <vmmapi.h>

#include "acpi.h"
#include "acpi_device.h"

/**
 * List entry to enumerate all resources used by an ACPI device.
 *
 * @param chain Used to chain multiple elements together.
 * @param type  Type of the ACPI resource.
 * @param data  Data of the ACPI resource.
 */
struct acpi_resource_list_entry {
	SLIST_ENTRY(acpi_resource_list_entry) chain;
	UINT32 type;
	ACPI_RESOURCE_DATA data;
};

/**
 * Holds information about an ACPI device.
 *
 * @param vm_ctx VM context the ACPI device was created in.
 * @param name   Name of the ACPI device.
 * @param hid    Hardware ID of the ACPI device.
 * @param crs    Current resources used by the ACPI device.
 */
struct acpi_device {
	struct vmctx *vm_ctx;
	const char *name;
	const char *hid;
	SLIST_HEAD(acpi_resource_list, acpi_resource_list_entry) crs;
};

int
acpi_device_create(struct acpi_device **const new_dev,
    struct vmctx *const vm_ctx, const char *const name, const char *const hid)
{
	if (new_dev == NULL || vm_ctx == NULL || name == NULL || hid == NULL) {
		return (EINVAL);
	}

	struct acpi_device *const dev = calloc(1, sizeof(*dev));
	if (dev == NULL) {
		return (ENOMEM);
	}

	dev->vm_ctx = vm_ctx;
	dev->name = strdup(name);
	dev->hid = strdup(hid);
	SLIST_INIT(&dev->crs);
	if (dev->name == NULL || dev->hid == NULL) {
		acpi_device_destroy(dev);
		return (ENOMEM);
	}

	*new_dev = dev;

	return (0);
}

void
acpi_device_destroy(struct acpi_device *const dev)
{
	if (dev == NULL) {
		return;
	}

	struct acpi_resource_list_entry *res;
	while (!SLIST_EMPTY(&dev->crs)) {
		res = SLIST_FIRST(&dev->crs);
		SLIST_REMOVE_HEAD(&dev->crs, chain);
		free(res);
	}
	
	free(__DECONST(void *, dev->hid));
	free(__DECONST(void *, dev->name));
	free(dev);
}

int
acpi_device_add_res_fixed_ioport(struct acpi_device *const dev,
    const UINT16 port, const UINT8 length)
{
	if (dev == NULL) {
		return (EINVAL);
	}

	struct acpi_resource_list_entry *const res = calloc(1, sizeof(*res));
	if (res == NULL) {
		return (ENOMEM);
	}

	res->type = ACPI_RESOURCE_TYPE_FIXED_IO;
	res->data.FixedIo.Address = port;
	res->data.FixedIo.AddressLength = length;

	SLIST_INSERT_HEAD(&dev->crs, res, chain);

	return (0);
}

int
acpi_device_add_res_fixed_memory32(struct acpi_device *const dev,
    const UINT8 write_protected, const UINT32 address, const UINT32 length)
{
	if (dev == NULL) {
		return (EINVAL);
	}

	struct acpi_resource_list_entry *const res = calloc(1, sizeof(*res));
	if (res == NULL) {
		return (ENOMEM);
	}

	res->type = ACPI_RESOURCE_TYPE_FIXED_MEMORY32;
	res->data.FixedMemory32.WriteProtect = write_protected;
	res->data.FixedMemory32.Address = address;
	res->data.FixedMemory32.AddressLength = length;

	SLIST_INSERT_HEAD(&dev->crs, res, chain);

	return (0);
}

static void
acpi_device_write_dsdt_crs(const struct acpi_device *const dev)
{
	const struct acpi_resource_list_entry *res;
	SLIST_FOREACH(res, &dev->crs, chain) {
		switch (res->type) {
		case ACPI_RESOURCE_TYPE_FIXED_IO:
			dsdt_fixed_ioport(res->data.FixedIo.Address,
			    res->data.FixedIo.AddressLength);
			break;
		case ACPI_RESOURCE_TYPE_FIXED_MEMORY32:
			dsdt_fixed_mem32(res->data.FixedMemory32.Address,
			    res->data.FixedMemory32.AddressLength);
			break;
		default:
			assert(0);
			break;
		}
	}
}

void
acpi_device_write_dsdt(const struct acpi_device *const dev)
{
	if (dev == NULL) {
		return;
	}

	dsdt_line("");
	dsdt_line("  Scope (\\_SB)");
	dsdt_line("  {");
	dsdt_line("    Device (%s)", dev->name);
	dsdt_line("    {");
	dsdt_line("      Name (_HID, \"%s\")", dev->hid);
	dsdt_line("      Name (_STA, 0x0F)");
	dsdt_line("      Name (_CRS, ResourceTemplate ()");
	dsdt_line("      {");
	dsdt_indent(4);
	acpi_device_write_dsdt_crs(dev);
	dsdt_unindent(4);
	dsdt_line("      })");
	dsdt_line("    }");
	dsdt_line("  }");
}
