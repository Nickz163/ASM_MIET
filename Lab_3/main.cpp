#include <iostream>
using namespace std;
extern "C" int yx(int i);
int main()
{
int x=15, y=3;
y = yx(x);
cout << y <<endl;
return 0;
}
