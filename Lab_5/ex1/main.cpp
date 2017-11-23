//Лабораторная работа 5.
//Программирование сопроцессора
// ЗАДАНИЕ 1.
/*
    Разработайте программу на языке C++, выполняющую вычисления над вещественными
числами одинарной точности (тип float).
    Проверьте, что программа действительно работает с операндами одинарной
точности, а не приводит к типу float окончательный результат.
    Сравните полученный результат с теоретическим. Объясните результат.
    Измените тип операндов на double. Объясните результат.

ВАРИАНТ 2
Найти значение выражения ((a+b)^2-(a^2+2ab))/b^2
для различных значений a, b (пример Лавренова):
a = 95; b = 1,
a = 95; b = 0,1

Теоретические результаты:
((95+1)^2-(95^2+2*95*1))/1^2 = 1 - без комментариев
((95+0,1)^2-(95^2+2*95*0,1))/0,1^2 = 1
0,1 нельзя точно представить в двоичном виде
b = 0.10000000149011612 стандартная точность для (7 - 8 десятичных знаков)
float сохраняется.
(95+0,1) = 95.0999984741211 мантисса также составляет 7 - 8 десятичных знаков
(95+0,1)^2 = 9044.009765625 теперь если от этого числа отнять 9044,
то в мантиссу уже будет входить другой сектор этого числа, который раньше в неё
не входил, отсюда и неточность
То же самое и с double
*/

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
void func(T a, T b)
{
    cout <<"Тип результата: "<< typeid(((a+b)*(a+b)-(a*a+2*a*b))/b/b).name() << endl;
    cout << "a = "<<a<<", b = "<<b<<", значение выражения = " <<
            ((a+b)*(a+b)-(a*a+2*a*b))/b/b <<setprecision(20)<< endl;
T c =(a+b);
T c3 = (a+b);
T c3t = c*c3;
T c1 =(a*a+2*a*b);
        T c2=c3t-c1;
}

int main()
{
    double a, b;
    a = 95;
    b = 1;
    func((float)a, (float)b);
    func(a, b);
    b = 0.1;
    func((float)a, (float)b);
    func(a, b);
    return 0;
}
