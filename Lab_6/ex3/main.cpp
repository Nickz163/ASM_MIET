//Лабораторная работа 6.
//Программирование ветвящихся и циклических алгоритмов
// ЗАДАНИЕ 3.
/*
Задайте с клавиатуры N и напечатайте первые N членов последовательности (целой).


ВАРИАНТ 2
Арифметическая прогрессия a0 = 0, ai+1 = ai + x, x ввести с клавиатуры
*/

#include <iostream>

using namespace std;

int main()
{
    int N, x, a;
    cout << "Введите N и x: ";
    cin >> N >> x;
    int* M = new int[N+1];
int I=N;

    __asm__ __volatile__ (
                        "xorl %[A],%[A]\n"      // Получаем 0

                        "begin_iteration:\n"
                        "movl %[A], (%[M], %[N], 4)\n"
                            "cmpl $0, %[N]\n"
                            "je end_loop\n"     // Если N = 0
                            "addl %[X], %[A]\n" // ai+1 = ai + x
                            "decl %[N]\n"       // Декремент
                            "jmp begin_iteration\n"
                        "end_loop:\n"
                        :[A] "+r" (a), [N] "+r" (N)
                        :[X] "r" (x), [M]"r"(M)

                        :"cc","memory"
                    );
    cout << "Результат: ";
    for (int i=0; i<I+1; i++)
    cout<<M[I-i]<<"\t";
    delete[] M;
    return 0;
}
