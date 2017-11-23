//Лабораторная работа 5.
//Программирование сопроцессора
// ЗАДАНИЕ 1.
/*
    Составьте программу calc для вычисления выражения с использованием
сопроцессора в соответствии со своим вариантом.

ВАРИАНТ 2
Найти значение выражения sin(x) · cos(0.9x)

*/

#include <iostream>

using namespace std;

int main()
{
    const double a = 0.9;
    double x = 0;
    double y;
    __asm__ __volatile__ (
                        "fldl %[X]\n"          // st(0) = %[X]
                        "fsin\n"               // st(0) = sin(%[X])
                        "fldl %[X]\n"          // st(0) = %[X], st(1) = sin(%[X])
                        "fmull %[A]\n"         // st(0) = %[A]*%[X], st(1) = sin(%[X])
                        "fcos\n"               // st(0) = cos(%[A]*%[X]), st(1) = sin(%[X])
                        "fmulp\n"              // st(0) = cos(%[A]*%[X]) · sin(%[X])
                        "fstpl %[Y]\n"         // %[Y] = cos(%[A]*%[X]) · sin(%[X]) стек пуст
                        :[Y] "=m" (y)
                        :[X] "m" (x), [A]"m"(a)
                        :"cc"
                    );
    cout << "Результат: "<< y << endl;
    return 0;
}
