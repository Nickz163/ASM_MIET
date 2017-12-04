// Лабораторная работа 7.
// Использование массивов
// ЗАДАНИЕ 2.
/*

Обработайте массив целых чисел alpha[] (выделение памяти и заполнение
массива может быть выполнено на языке высокого уровня).

Вариант 2.

Найти максимальный элемент массива

*/

#include <iostream>
#include <climits>

using namespace std;

int main()
{
    const int C = 10;
    long long alpha[C];
    cout << "Элементы массива: ";
    for (int i = 0; i < 10; i++)
    {
        alpha[i] = rand()%1000;
        cout << alpha[i]<< '\t';
    }
    cout << endl;
    long long max = -1000, i = C-1;
      __asm__ __volatile__ (  "begin_iteration:\n"
                              "cmpq $0, %[I]\n"
                                "je end_loop\n"      // Если i = 0
                                "cmpq (%[A], %[I], 8), %[M]\n"
                                "cmovl (%[A], %[I], 8), %[M]\n"
                                "decq %[I]\n"
                                "jmp begin_iteration\n"
                            "end_loop:\n"
                            :[M] "+r" (max), [I]"+r"(i)
                            :[A]"r"(alpha), [C]"r"(C)
                            :"cc"
                        );
    cout << "Максимальный элемент массива = " << max << endl;
    return 0;
}

