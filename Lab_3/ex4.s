.LC0:
        .string "x=%d\ny=%d\n"
.globl main # точка входа (stdlib)
main:
pushq   %rbp
movq    %rsp, %rbp
# Инициализация
movl    $4, %eax # b
movl    $5, %ecx # a
call foo4
movl    %eax, %esi #x
movl    %ecx, %esi #y
movl    $.LC0, %edi
call    printf
leave   
xor %eax, %eax 
ret
