//Лабораторная работа 4.
//Использование ассемблерных вставок в программах на C++
// ЗАДАНИЕ 1.
/*
    Разработайте и выполните программу, в которой реализуйте при помощи
ассемблерной вставки.
    Сложение целых чисел со знаком. (2 ВАРИАНТ)
    После команды сложения проанализируйте соответствующий флаг состояния
процессора, и, в зависимости от его значения, выведитерезультат и строку
«Результат верный» (если не было переполнения) или«Результат неверный»
(при переполнении).


Platform: Linux Ubuntu 16.04.3 LTS x86_64
Compiler: GNU GCC 7.2.0
*/

#include <iostream>

using namespace std;

int main()
{
    cout<< "Введите 2 целых числа: ";
    int a=0, b=0;
    cin>>a>>b;
    __asm__ __volatile__ (
                "addl %[b], %[a]\n" // Сложение
                :[a] "=rm" (a)
                :[b] "rm" (b)
                :"cc"
            );
    __asm__ goto("jo %l0" :::: gt); // Если OF = 1
    cout <<"Сумма: "<< a <<"\nРезультат верный\n";
    return 0;
    gt:
    cout <<"Сумма: "<< a <<"\nРезультат неверный\n";
    return 0;
}
