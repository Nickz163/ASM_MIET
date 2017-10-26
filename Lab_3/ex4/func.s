x:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$2, %eax
	subl	24(%rbp), %eax
	xorl	16(%rbp), %eax
	xorl	$2, %eax
	popq	%rbp
	ret

y:
	pushq	%rbp
	movq	%rsp, %rbp
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	16(%rbp), %eax
	addl	%eax, %eax
	imull	24(%rbp), %eax
	popq	%rbp
	ret

	.globl	func
func:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$48, %rsp
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, %edx
	movl	16(%rbp), %ecx
	call	x
	movl	%eax, -8(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, %edx
	movl	16(%rbp), %ecx
	call	y
	movl	%eax, -4(%rbp)
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
