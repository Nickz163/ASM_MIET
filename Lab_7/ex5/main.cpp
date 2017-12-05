// Лабораторная работа 7.
// Использование массивов
// ЗАДАНИЕ 5.
/*

Опишите вставку либо функцию, инициализирующую массив
заданной длины N первыми N элементами последовательности из задания 3
лабораторной работы Л6.

ВАРИАНТ 2

Арифметическая прогрессия a0 = 0, ai+1 = ai + x, x ввести с клавиатуры

*/

#include <iostream>

using namespace std;

int main()
{
    long long N, x, a=0;
    cout << "Введите N и x: ";
    cin >> N >> x;
    long long* M = new long long[N];
    long long j=0;

    __asm__ __volatile__ (
                        "xorq %[A], %[A]\n"      // Получаем 0

                        "begin_iteration:\n"
                        "movq %[A], (%[M], %[J], 8)\n"
                            "cmpq %[J], %[N]\n"
                            "je end_loop\n"     // Если N = 0
                            "addq %[X], %[A]\n" // ai+1 = ai + x
                            "incq %[J]\n"       // Декремент
                            "jmp begin_iteration\n"
                        "end_loop:\n"
                        :[A] "+r" (a), [J] "+r" (j)
                        :[X] "r" (x), [M]"r"(M), [N] "r" (N)

                        :"cc","memory"
                    );
    cout << "Результат: ";
    for (int i=0; i<N; i++)
        cout<<M[i]<<"\t";
    cout<<endl;
    delete[] M;
    return 0;
}
