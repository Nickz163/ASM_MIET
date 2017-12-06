// Лабораторная работа 7.
// Использование массивов
// ЗАДАНИЕ 3.
/*

Cоздайте, используя язык высокого уровня, массив beta[] из структур,
содержащих целый ключ и вещественное значение.
Определите размер массива и расположение элементов (используя
возможности языка высокого уровня или IDE).

1. Каков размер структуры (в байтах)?
2. Каковы размеры полей структуры (в байтах)?
3. Насколько отличаются адреса соседних полей структуры (в байтах)?
4. Каков общий размер массива (в байтах)?
5. Как получить адрес поля элемента массива, зная номер элемента, адрес
   начала массива и имя поля?

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
    const int C = 10;
    str beta[C];
    for (int i = 0; i < 10; i++){
        beta[i].key = i;
        beta[i].value = i;
    }

    //1

    cout << "1. Размер структуры: "<<sizeof(beta[0]) << " байт" << endl;

    //2

    cout << "2. Размер поля int key      - " << sizeof(beta[0].key) << " байта" << endl;
    cout << "   Размер поля double value - " << sizeof(beta[0].value) << " байт" << endl;

    //3

    int razn = (unsigned long long)&beta[1] - (unsigned long long)&beta[0];
        cout << "3. Адреса соседних элементов массива отличаются на "
             << razn << " байт" << endl;

    //4

    cout << "4. Общий размер массива - " << sizeof(beta) << " байт" << endl;

    //5

    int num = 2;
    cout << "5. Адрес 0 элемента (поле key) - " << beta << endl;
    cout << "   Адрес поля key " << num << " элемента   - " << &beta[num].key << endl;
    cout << "   Адрес поля value " << num << " элемента - " << &beta[num].value << endl;

    return 0;
}