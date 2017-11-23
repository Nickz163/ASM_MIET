//Лабораторная работа 6.
//Программирование ветвящихся и циклических алгоритмов
// ЗАДАНИЕ 1.
/*
    Вычислите для заданных целых x, y

ВАРИАНТ 2
            ⎧x,     x + y < 4
f(x, y) =   ⎨
            ⎩y + 2, x + y >= 4
*/

#include <iostream>

using namespace std;

int main()
{
    int f, x=2, y=4, f1;
    __asm__ __volatile__ (
                           "movl %[X], %[U]\n"          // f = x
                           "addl %[Y], %[U]\n"          // f = x + y
                          // "cmovge %[X], %[F]\n"
                           //"jge setting_1\n"            // if (f >= 4)
                         //  "cmovnge %[X], %[F]\n"          // f = x
                           //"jmp end_check\n"            // и переход к концу
                           //"setting_1:\n"
                               "movl %[Y], %[F]\n"      // f = y
                               "addl $2, %[F]\n"        // f= y + 2
                               "cmpl $4, %[U]\n"
                               "cmovl %[X], %[F]\n"
                          // "end_check:\n"               // метка конца
                           :[F] "+r" (f), [U] "+r" (f1)
                           :[X] "r" (x), [Y]"r"(y)
                           :"cc"
                       );
    cout << "f = "<< f << endl;
    return 0;
}
