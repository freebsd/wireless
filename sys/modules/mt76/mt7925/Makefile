
DEVDIR=	${SRCTOP}/sys/contrib/dev/mediatek/mt76/mt7925

.PATH: ${DEVDIR}

WITH_DEBUGFS=		0
WITH_DEV_COREDUMP=	1

KMOD=	if_mt7925

# Common stuff.
SRCS=	init.c main.c mac.c mcu.c

# PCI
SRCS+=	pci.c pci_mac.c pci_mcu.c

# USB
#SRCS+=	usb.c

.if defined(WITH_DEBUGFS) && ${WITH_DEBUGFS} > 0
SRCS+=	debugfs.c
CFLAGS+=	-DCONFIG_MT7915_DEBUGFS=${WITH_DEBUGFS}
.endif

CFLAGS+=	-DKBUILD_MODNAME='"mt7925"'
CFLAGS+=	-I${DEVDIR}

.include <bsd.kmod.mk>
