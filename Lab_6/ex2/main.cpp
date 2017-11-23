//Лабораторная работа 6.
//Программирование ветвящихся и циклических алгоритмов
// ЗАДАНИЕ 2.
/*
    Вычислите для заданного вещественного x

ВАРИАНТ 2
         ⎧x + x / 2 + x / 4 + x / 8, x >= 0
y(x) =   ⎨
         ⎩x - 1,                     x < 0

*/

#include <iostream>

using namespace std;

int main()
{
    double x = -1.5;
    double y;
    __asm__ __volatile__ (
                        "fldz\n"                    // st(0) = 0
                        "fldl %[X]\n"               // st(0) = %[X], st(1) = 0
                        "fcomi %%st(1), %%st(0)\n"    // сравнение (меняются CF, ZF, PF)
                        "jb setting_1\n"            // CF = 1, st(0) < st(1), st(0) − st(1) < 0
                        "faddp %%st(0), %%st(1)\n"    // st(0) = %[X]
                        "fld1\n"                    // st(0) = 1, st(1) = %[X],
                        "fld1\n"                    // st(0) = 1, st(1) = 1, st(2) = %[X]
                        "faddp\n"                   // st(0) = 2, st(1) = %[X]
						"fldl %[X]\n"  				// st(0) = %[X], st(1) = 2, st(2) = %[X]

                        "fdiv %%st(1), %%st(0)\n"   // st(0) = %[X]/2, st(1) = 2, st(2) = %[X]
                        "fadd %%st(0), %%st(2)\n"   // st(0) = %[X]/2, st(1) = 2, st(2) = %[X]+%[X]/2
                        "fdiv %%st(1), %%st(0)\n"   // st(0) = %[X]/4, st(1) = 2, st(2) = %[X]+%[X]/2
                        "fadd %%st(0), %%st(2)\n"   // st(0) = %[X]/4, st(1) = 2, st(2) = %[X]+%[X]/2+%[X]/4
                        "fdiv %%st(1), %%st(0)\n"   // st(0) = %[X]/8, st(1) = 2, st(2) = %[X]+%[X]/2+%[X]/4
                        "fadd %%st(0), %%st(2)\n"   // st(0) = %[X]/8, st(1) = 2, st(2) = %[X]+%[X]/2+%[X]/4+%[X]/8
                        "fstpl %[Y]\n"
                        "fstpl %[Y]\n"
                        "fstpl %[Y]\n"
                        "jmp end_check\n"           // переход к концу
                        "setting_1:\n"
                            "fld1\n"                // st(0) = 1, st(1) = %[X], st(2) = 0
                            "fsubp\n"               // st(0) = %[X] - 1, st(1) = 0
                          "fsubr %%st(1), %%st(0)\n"
                            "faddp\n"               // st(0) = %[X] - 1
                            "fstpl %[Y]\n"

                        "end_check:\n"              // метка конца
                        :[Y] "+m" (y)
                        :[X] "m" (x)
                        :"cc"
                    );
    cout << "Результат: "<< y << endl;
    return 0;
}
