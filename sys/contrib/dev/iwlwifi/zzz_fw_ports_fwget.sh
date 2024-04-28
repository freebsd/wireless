#!/bin/sh
#-
# SPDX-License-Identifier: BSD-2-Clause
#
# Copyright (c) 2024 The FreeBSD Foundation
#
# This software was developed by Björn Zeeb
# under sponsorship from the FreeBSD Foundation.
#
# This is neither efficient nor elegant but we need it few times
# a year and it does the job.
#
#
# USAGE: please check out the correct tag/hash for ports in the
# linux-firmware.git repository you point this script to.
#
# USAGE: please make sure to pre-load if_iwlwifi.ko so that we
# have access to the sysctl.  You do not need to have a supported
# card in the system.
#

set -e

################################################################################
#
# Check pre-reqs
#
if [ $# -ne 1 ]; then
	printf "USAGE: %s /path/to/linux-firmware.git\n" $0 >&2
	exit 1
fi

if [ ! -d cfg/ -o ! -e cfg/bz.c ]; then
	printf "ERROR: run from iwlwifi driver directory; no cfg/bz.c here\n" >&2
	exit 1
fi

LFWDIR=${1}
if test ! -d ${LFWDIR} -o ! -e ${LFWDIR}/WHENCE; then
	printf "ERROR: cannot find linux-firmware.git at '%s'\n" ${LFWDIR} >&2
	exit 1
fi

kldstat -n if_iwlwifi.ko > /dev/null 2>&1
rc=$?
case ${rc} in
0)	;;
*)	printf "ERROR: please pre-load if_iwlwifi.ko (you do not need a device)\n" >&2
	exit 1
	;;
esac
sysctl -N compat.linuxkpi.iwlwifi_pci_ids_name > /dev/null 2>&1
rc=$?
case ${rc} in
0)	;;
*)	printf "ERROR: cannot get compat.linuxkpi.iwlwifi_pci_ids_name\n" >&2
	exit 1
	;;
esac

# We need to be in the config directory for simplicity.
cd cfg

################################################################################
#
# Helper functions.
#

#
# This uses a hack (cpp) to expand some macros for us and parses out the result
# which is the firmware name with the maximum FW version supported for that
# firmware.
# We then go and check that said firmware actually exists in linux-firmware.git
# and if there is a .pnvm file along with it.
# Given the filename is used as "flavor" at this point, we then group all the
# available firmware files from this flavor together and print it as a ports
# Makefile variable.
#
# We also print some other meta-data that callers will filter out depending on
# their needs to generate other lists and mappings.
#
list_fw()
{
( for f in `ls -1 [0-9]*.c | sort -n; ls -1 [a-zA-Z]*.c`; do

	l=$(cpp ${f} 2>&1 | awk '/^MODULE_FIRMWARE\(/ { gsub(/"/, ""); gsub("__stringify\\(", ""); gsub("\\);$", ""); gsub("\\)", ""); gsub("^MODULE_FIRMWARE\\(", ""); gsub(" ", ""); printf "%s\n", $0; }' | sort -n | uniq)
	lx=""
	for fx in ${l}; do
		if test -e ${LFWDIR}/${fx}; then
			lx="${lx} ${fx}"

			# Check for matching .pnvm file.
			px=$(echo ${fx} | awk '{ gsub("-[[:digit:]]*.ucode", ".pnvm"); print; }')
			if test -e ${LFWDIR}/${px}; then
				lx="${lx} ${px}"
			fi
		# else
		#	printf "NOTICE: no firmware file found for '%s'\n" ${fx} >&2
		fi
	done

	# Get a count so we can automatically add \\ apart from the last line.
	fn=$(echo "${lx}" | wc -w | awk '{ print $1 }')

	# echo "==> ${f} :: ${fn} :: ${lx}"

	if test ${fn} -gt 0; then

		# Ports FLAVOR names are [a-z0-9_].  If needed add more mangling magic here.
		flav=`echo ${f%%.c} | awk '{ printf "%s", tolower($0); }'`

		echo "FWS ${flav}"
		echo "DISTFILES_${flav}= \\"
		for fz in ${lx}; do echo "${fz}"; done | \
		awk -v fn=$fn -v fwg=${flav} '{
			if (FNR == fn) { x="" } else { x=" \\" };
			printf "\t%s${DISTURL_SUFFIX}%s\n", $0, x;
			fwn=$0;
			gsub("-[[:digit:]]*\.ucode$", "", fwn);
			printf "FWGET %s %s\n", fwg, fwn;
		}'
	fi
done )
}

################################################################################
#
# Generate the PORTS file template.
#

fwsl=$(list_fw | grep ^FWS | awk '{ print $2 }')
# Get a count so we can automatically add \\ apart from the last line.
fn=$(echo "${fwsl}" | wc -w | awk '{ print $1 }')

if test ${fn} -gt 0; then

	portsfile=$(mktemp -p /tmp iwlwifi-fwport.XXXXXX)

	:> ${portsfile}
	(
	echo "FWSUBS= \\"
	for sz in ${fwsl}; do echo "${sz}"; done | \
	awk -v fn=$fn '{ if (FNR == fn) { x="" } else { x=" \\" }; printf "\t%s%s\n", $0, x; }'

	echo
	echo "# Do not prefix with empty \${FWSUBDIR}/!"
	list_fw | grep -v ^FWS | grep -v ^FWGET

	echo
	echo "DISTFILES_\${FWDRV}= \\"
	for sz in ${fwsl}; do echo "${sz}"; done | \
	awk -v fn=$fn '{ if (FNR == fn) { x="" } else { x=" \\" }; printf "\t${DISTFILES_%s}%s\n", $0, x; }'
	echo "DISTFILES_\${FWDRV}_lic="
	) >> ${portsfile}

	printf "INFO: wifi-firmware-iwlwifi-kmod template at %s\n" ${portsfile} >&2
fi

################################################################################
#
# Generate a temporary firmware -> flavor mapping table for fwget generation.
#

mapfile=$(mktemp -p /tmp iwlwifi-mapfile.XXXXXX)
:> ${mapfile}

fwgl=$(list_fw | grep FWGET)
# Get a count so we can automatically add \\ apart from the last line.
fn=$(echo "${fwgl}" | wc -w | awk '{ print $1 }')
if test ${fn} -gt 0; then

	(
	list_fw | grep FWGET | grep -v '.pnvm' | \
	while read x flav fw; do
		printf "%s\t%s\n" ${fw} ${flav}
	done | \
	sort -n | uniq
	) >> ${mapfile}
fi

################################################################################
#
# Try to generate the PCI ID -> port flavor mapping
#
# We get PCI ID, description, firmware base from the sysctl and can work our
# way back from fw name base to flavor via the mapping table file.
#

fwgetfile=$(mktemp -p /tmp iwlwifi-fwget.XXXXXX)
:> ${fwgetfile}

sysctl -n compat.linuxkpi.iwlwifi_pci_ids_name | \
grep -v ^$ | \
awk 'BEGIN { FS="\t"; }
{
	# No firmware name; skip.
	if ($3 == "(null)") { next; };
	FW=$3;

	split($1, i, "/");
	gsub("\t.*$", "", i[4]);

	# Not an Intel Vednor ID; skip.
	if (i[1] != "0x8086") { next; };

	# No defined device ID; skip.
	if (i[2] == "0xffff") { next; };

	# Adjust wildcards or a ill-printed 0.
	if (i[3] == "0xffffffff") { i[3] = "*"; };
	if (i[4] == "000000") { i[4] = "0x0000"; };
	if (i[4] == "0xffff") { i[4] = "*"; };

	printf "%s\t%s/%s/%s\n", FW, i[2], i[3], i[4];
}' | \
sort | uniq | \
while read fw match; do

        flav=$(awk -v fw=$fw '{ if ($1 == fw) { print $2; } }' ${mapfile})
        #echo "${fw} :: ${match} :: ${flav}"

        if test "${flav}" != ""; then
                printf "${fw}\t${match}\t${flav}\n"
        else
                #echo "NO FLAV ${fw} ${match}" >&2
        fi

done | \
awk 'BEGIN { FS="\t"; FWN=""; }
{
	FW=$1;
	if (FWN != FW) { printf "\n\t# %s\n", FW; FWN=FW; };

	printf "\t%s) addpkg \"wifi-firmware-iwlwifi-kmod-%s\"; return 1 ;;\n", $2, $3;
} END {
	printf "\n";
}' >> ${fwgetfile}

printf "INFO: fwget pci_network_intel template at %s\n" ${fwgetfile} >&2

################################################################################
#
# Try to build the iwlwififw.4 bits too.
#

dl=$(sysctl -n compat.linuxkpi.iwlwifi_pci_ids_name | \
grep -v ^$ | uniq | \
awk '
{
	# Sourt out duplicate lines.
	if (dup[$0]++) { next; }

	# my ($ids, $name, $fw) = split /\t/;
	split($0, a, "\t");
	ids=a[1];
	name=a[2];
	fw=a[3];

	#my ($v, $d, $sv, $sd) = split("/", $ids);
	split(ids, i, "/");
	gsub("^0xffff", "any", i[1]);
	gsub("^0xffff", "any", i[2]);
	gsub("^0xffff+", "any", i[3]);
	gsub("^0xffff", "any", i[4]);

	# iwlwififw.4
	printf ".It \"\"\n.It %s\n.It %s Ta %s Ta %s Ta %s Ta %s\n", name, i[1], i[2], i[3], i[4], fw;

	# wiki
	# XXX TODO possibly quote some in `` to avoid automatic linking?
	# || PCI IDs || Chipset Name || Firmware prefix || Comment ||
	printf "WIKI || %s / %s / %s / %s || %s || %s || ||\n", i[1], i[2], i[3], i[4], name, fw;
	if ((FNR % 25) == 0) { printf "WIKI \n"; }
}')

manfwfile=$(mktemp -p /tmp iwlwifi-iwlwififw4.XXXXXX)
:> ${manfwfile}
echo "${dl}" | grep -v ^WIKI >> ${manfwfile}
printf "INFO: share/man/man4/iwlwififw.4 template at %s\n" ${manfwfile} >&2

wikifile=$(mktemp -p /tmp iwlwifi-wiki.XXXXXX)
:> ${wikifile}
echo "${dl}" | awk '/^WIKI / { gsub("^WIKI ", ""); print; }' >> ${wikifile}
printf "INFO: WIKI template at %s\n" ${wikifile} >&2


################################################################################
#
# Cleanup
#
rm ${mapfile}

# end
