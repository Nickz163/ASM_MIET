.globl foo4
foo4:
mov %ecx, %edx
mov %ecx, %edx
add %edx, %edx
imul %eax, %edx #edx - удвоенное произведение
imul %eax, %eax
imul %ecx, %ecx
sub %eax, %ecx
mov %ecx, %eax # eax - разность квадратов
