.globl yx
yx:
mov %edi, %eax
and $3, %eax
sub %edi, %eax
ret
