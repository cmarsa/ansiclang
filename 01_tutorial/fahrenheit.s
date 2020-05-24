	.file	"fahrenheit.c"
	.text
	.section	.rodata
.LC5:
	.string	"%3.0f %6.1f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	pxor	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
	movss	.LC1(%rip), %xmm0
	movss	%xmm0, -12(%rbp)
	movss	.LC2(%rip), %xmm0
	movss	%xmm0, -8(%rbp)
	movss	-16(%rbp), %xmm0
	movss	%xmm0, -20(%rbp)
	jmp	.L2
.L3:
	cvtss2sd	-20(%rbp), %xmm0
	movsd	.LC3(%rip), %xmm1
	subsd	%xmm1, %xmm0
	movapd	%xmm0, %xmm1
	movsd	.LC4(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -4(%rbp)
	cvtss2sd	-4(%rbp), %xmm1
	cvtss2sd	-20(%rbp), %xmm0
	leaq	.LC5(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
	movss	-20(%rbp), %xmm0
	addss	-8(%rbp), %xmm0
	movss	%xmm0, -20(%rbp)
.L2:
	movss	-12(%rbp), %xmm0
	comiss	-20(%rbp), %xmm0
	jnb	.L3
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC1:
	.long	1133903872
	.align 4
.LC2:
	.long	1101004800
	.align 8
.LC3:
	.long	0
	.long	1077936128
	.align 8
.LC4:
	.long	1908874354
	.long	1071761180
	.ident	"GCC: (Ubuntu 9.3.0-10ubuntu2) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
