/*
 * Copyright (c) 2004 Suleiman Souhlal
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

 #include <machine/asm.h>
	.globl  CNAME(_ctx_done)
	.globl  CNAME(abort)

 ENTRY(_ctx_start)
	mtlr	%r14
	blrl			/* branch to start function */
	mr	%r3,%r15	/* pass pointer to ucontext as argument */
	bl	CNAME(_ctx_done) /* branch to ctxt completion func */

	/*
	 * we should never return from the
	 * above branch.
	 */
	/* Don't bother saving off %r30, we're already in a bad state. */
	bcl	20,31,1f
1:	mflr	%r30
	mr	%r3,%r30		# save for _DYNAMIC
	addis	%r30,%r30,_GLOBAL_OFFSET_TABLE_-1b@ha
	addi	%r30,%r30,_GLOBAL_OFFSET_TABLE_-1b@l
	bl	PIC_PLT(CNAME(abort))	/* abort */
 END(_ctx_start)

	.section .note.GNU-stack,"",%progbits
