#include <iostream>
#include <fstream>
#include <bitset>
#include <limits.h>
#include <typeinfo>
#define OPERATION_DEC(x, operat, y, rez) (cout <<dec<< x<<' '<<operat<<' '<<y <<" = "<< rez << "\t\t")
#define OPERATION_HEX(x, operat, y, rez) (cout <<hex<<"0x"<< x<<' '<<operat<<" 0x"<<y <<" = 0x"<< rez << endl)
#define PRINT_SIZE(type, name); cout << sizeof(type) << "\t" << name << endl;
using namespace std;

union Memory
{
	unsigned short us;
	signed short ss;
};
void viewFormsOfRepresentation(Memory x)
{
	cout << "Hexadecimal form: \t" << hex << x.us << endl;
	cout << "Unsigned decimal: \t" << dec << x.us << endl;
	cout << "Signed decimal: \t" << dec << x.ss << endl;
	cout << "Binary form: \t" << bitset<16>(x.us) << endl;
}
void ex2()
{
	Memory x, y;
	x.ss = -2;
	y.ss = 16385;
	cout << "\tx" << endl;
	viewFormsOfRepresentation(x);
	cout << "\n\ty" << endl;
	viewFormsOfRepresentation(y);
}
void ex3()
{
	Memory sign_max, sign_min, unsign_max, unsign_min;
	sign_max.ss = SHRT_MAX;
	sign_min.ss = SHRT_MIN;
	unsign_max.ss = USHRT_MAX;
	unsign_min.ss = 0;
	cout << "\tSigned max" << endl;
	viewFormsOfRepresentation(sign_max);
	cout << "\n\tSigned min" << endl;
	viewFormsOfRepresentation(sign_min);
	cout << "\n\tUnsigned max" << endl;
	viewFormsOfRepresentation(unsign_max);
	cout << "\n\tUnsigned min" << endl;
	viewFormsOfRepresentation(unsign_min);
}
template<typename T>
void op(T x, T y)
{
	cout << endl;
	OPERATION_DEC(x, '&', y, (T)(x&y));
	OPERATION_HEX(x, '&', y, (T)(x&y));
	cout << endl;
	OPERATION_DEC(x, '|', y, (T)(x | y));
	OPERATION_HEX(x, '|', y, (T)(x | y));
	cout << endl;
	OPERATION_DEC(x, '^', y, (T)(x^y));
	OPERATION_HEX(x, '^', y, (T)(x^y));
	cout << endl;
	cout << "~" << dec << x << " = " << (T)(~x) << "\t\t\t";
	cout << "~0x" << hex << x << " = 0x" << (T)(~x) << endl;
	cout << endl;
	cout << "~" << dec << y << " = " << (T)(~y) << "\t\t\t";
	cout << "~0x" << hex << y << " = 0x" << (T)(~y) << endl;
	cout << endl;
	cout << "neg(" << dec << x << ") = " << (T)(USHRT_MAX - x + 1) << "\t\t";
	cout << "neg(0x" << hex << x << ") = 0x" << (T)(USHRT_MAX - x + 1) << endl;
	cout << endl;
	cout << "neg(" << dec << y << ") = " << (T)(USHRT_MAX - y + 1) << "\t\t";
	cout << "neg(0x" << hex << y << ") = 0x" << (T)(USHRT_MAX - y + 1) << endl;
	cout << endl;
	OPERATION_DEC(x, "<<", y, (T)(x << y));
	OPERATION_HEX(x, "<<", y, (T)(x << y));
	cout << endl;
	OPERATION_DEC(x, ">>", y, (T)(x >> y));
	OPERATION_HEX(x, ">>", y, (T)(x >> y));
	cout << endl;
}
void ex4()
{
	Memory x, y;
	x.us = 0x8008;
	y.us = 0x1111;
	op(x.us, y.us);
	x.us = 0x0005;
	y.us = 0x0002;
	op(x.us, y.us);
}
void ex5()
{
	Memory x, y;
	x.ss = 0x8008;
	y.ss = 0x1111;
	op(x.ss, y.ss);
	x.ss = 0x0005;
	y.ss = 0x0002;
	op(x.ss, y.ss);
}
template<typename T>
void op6(T x, T y)
{
	cout << endl;
	OPERATION_HEX(x, '&', y, (T)(x&y));
	cout << endl;
	OPERATION_HEX(x, '|', y, (T)(x | y));
	cout << endl;
	OPERATION_HEX(x, '^', y, (T)(x^y));
	cout << endl;
	cout << "~0x" << hex << x << " = 0x" << (T)(~x) << endl;
	cout << endl;
	cout << "~0x" << hex << y << " = 0x" << (T)(~y) << endl;
	cout << endl;
	cout << "neg(0x" << hex << x << ") = 0x" << (T)(USHRT_MAX - x + 1) << endl;
	cout << endl;
	cout << "neg(0x" << hex << y << ") = 0x" << (T)(USHRT_MAX - y + 1) << endl;
	cout << endl;
	OPERATION_HEX(x, "<<", y, (T)(x << y));
	cout << endl;
	OPERATION_HEX(x, ">>", y, (T)(x >> y));
	cout << endl;
}
void ex6()
{
	Memory x, y, x1, y1;
	x.us = 0x8008;
	y.us = 0x1111;
	x1.us = 0x0005;
	y1.us = 0x0002;
	cout << "\tSigned int" << endl;
	op6((signed int)x.ss, (signed int)y.ss);
	op6((signed int)x1.ss, (signed int)y1.ss);
	cout << "\tUnsigned int" << endl;
	op6((unsigned int)x.us, (unsigned int)y.us);
	op6((unsigned int)x1.us, (unsigned int)y1.us);
}
void ex7()
{
	int x = 0x12345678;
	char* str1 = "abcd";
	char* str2 = "абвг";
	wchar_t* wstr1 = L"abcd";
	wchar_t* wstr2 = L"абвг";

}
void ex8()
{
	signed short x = SHRT_MAX;
	cout << "\tSigned short" << endl;
	cout << hex << "SHRT_MAX = 0x" << x << '\t' << "SHRT_MAX + 1 = 0x" << (signed short)(x + 1) << endl;
	unsigned short y = USHRT_MAX;
	cout << "\tUnsigned short" << endl;
	cout << hex << "USHRT_MAX = 0x" << y << '\t' << "USHRT_MAX + 1 = 0x" << (unsigned short)(y + 1) << endl;
}
void ex9()
{
	PRINT_SIZE(char, "char");
	PRINT_SIZE(bool, "bool");
	PRINT_SIZE(wchar_t, "wchar_t");
	PRINT_SIZE(short, "short");
	PRINT_SIZE(int, "int");
	PRINT_SIZE(long, "long");
	PRINT_SIZE(long long, "long long");
	PRINT_SIZE(float, "float");
	PRINT_SIZE(double, "double");
	PRINT_SIZE(long double, "long double");
	PRINT_SIZE(size_t, "size_t");
	PRINT_SIZE(ptrdiff_t, "ptrdiff_t");
	PRINT_SIZE(void*, "void*");

}
int main()
{
	// 2задание
	cout << endl << "\tExercise 2" << endl;
	ex2();
	cout << endl;

	//3 задание
	cout << endl << "\tExercise 3" << endl;
	ex3();

	//4 задание
	cout << endl << "\tExercise 4" << endl;
	ex4();
	cout << endl;

	//5 задание
	cout << endl << "\tExercise 5" << endl;
	ex5();
	cout << endl;

	//6 задание
	cout << endl << "\tExercise 6" << endl;
	ex6();
	cout << endl;

	//7 задание
	ex7();

	//8 задание
	cout << endl << "\tExercise 8" << endl;
	ex8();
	cout << endl;

	//9 задание
	cout << endl << "\tExercise 9" << endl;
	ex9();
	cout << endl;
	return 0;
}
