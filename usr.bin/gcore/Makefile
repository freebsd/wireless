#	@(#)Makefile	8.1 (Berkeley) 6/6/93

PROG=	gcore
SRCS=	elfcore.c gcore.c
LIBADD=	sbuf util

.if ${MACHINE_CPUARCH} == "aarch64" || ${MACHINE_ARCH} == "amd64" || \
    ${MACHINE_ARCH} == "powerpc64"
SRCS+=	elf32core.c
.endif

WARNS?=	1

.include <bsd.prog.mk>
