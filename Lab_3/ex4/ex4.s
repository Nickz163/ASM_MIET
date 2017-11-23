
	.def	main
main:
	pushq	%rbp
	movq	%rsp, %rbp
	subq	$32, %rsp
	movl	$25, %edx
	movl	$17, %ecx
	call	func
	movl	$0, %eax
	addq	$32, %rsp
	popq	%rbp
	ret
