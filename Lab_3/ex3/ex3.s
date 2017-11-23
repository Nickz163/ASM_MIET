	.def	main
main:
	subq	$40, %rsp
	call    ex3
	xorl	%eax, %eax
	addq	$40, %rsp
	ret
