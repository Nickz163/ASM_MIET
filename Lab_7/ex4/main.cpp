// Лабораторная работа 7.
// Использование массивов
// ЗАДАНИЕ 4.
/*

Реализуйте задание 2 для значений тех элементов массива beta[],
ключ которых равен заданному числу k. Если таких нет, вывести корректное
сообщение об этом.

Вариант 2.

Найти максимальный элемент массива

*/

#include <iostream>

using namespace std;

struct str
{
    long long key;
    double value;
};

int main()
{
    const int C = 2;
    str beta[C];
    cout << "Элементы массива: ";
    for (int i = 0; i < C; i++)
    {
        beta[i].key = 4;//i/2;
        beta[i].value = 1001+i;//rand()%1000;
        cout << beta[i].key << '-'<<beta[i].value<< '\t';
    }
    cout << endl;
    long long k = 4;          // заданное число
    long long i = (C-1)*2;
    double max, buf = -1001;

    // buf - как хранилище выталкиваемого из FPU "мусора", так и индикатор наличия ключа

    __asm__ __volatile__ (      "fldl %[BUF]\n"                    // st(0) = max

    /*begin_iteration : .....*/ "begin_iteration:\n"
                                "cmpq $0, %[I]\n"
              /*end_loop*/      "jl end_loop\n"                   // Если i = 0
                                "cmpq (%[B], %[I], 8), %[K]\n"    // Сравнение ключа с k
              /*end_iter*/      "jne end_iter\n"                  // Если они НЕ равны
                                                                  // else
                                "fldl 8(%[B], %[I], 8)\n"         // st(0) = beta[i], st(1) = max
                                "fcomi %%st(1), %%st(0)\n"        // Cравнение c max


                 /*small*/      "jbe small\n"                     // st(0) <= st(1)
                                "fxch\n"                          // st(0) = notMAX, st(1) = MAX

    /*small : ...............*/ "small:\n"
                                "fstpl %[BUF]\n"                   // st(0) = MAX

    /*end_iter: .............*/ "end_iter:\n"
                                "subq $2, %[I]\n"                 // Шаг = -2

       /*begin_iteration*/      "jmp begin_iteration\n"
    /*end_loop : ............*/ "end_loop:\n"
                                "fstpl %[M]\n"                      // max = st(0)

                            :[M] "=m" (max), [I]"+r"(i), [BUF]"+m"(buf)
                            :[B]"r"(beta), [K]"r"(k)
                        );
    if (buf == -1001)
        cout << "В массиве нет ключей равных " << k << endl;
    else
        cout << "Максимальный элемент массива = " << max << endl;
    return 0;
}
