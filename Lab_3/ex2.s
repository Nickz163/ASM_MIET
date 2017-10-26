.LC0:
        .string "%d\n"
.globl main # точка входа (stdlib)
main:
pushq   %rbp
movq    %rsp, %rbp
# Вычисления
mov $13, %eax
mov $13, %ecx
and $3, %eax
sub %ecx, %eax
#
movl    %eax, %esi
movl    $.LC0, %edi
call    printf
leave   #Команда копирует регистр ЕВР/ВР
#в ESP/SP, тем самым восстанавливая в регистре ESP/SP 
#то значение, которое было до вызова процедуры
xor %eax, %eax # A ^= A, то есть A = 0
ret # return A
