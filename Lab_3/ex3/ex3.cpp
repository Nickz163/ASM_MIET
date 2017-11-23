#include <cstdio>
#include <cstdlib>

extern "C"
void ex3() {
    int a;
    printf("Enter number: ");
    scanf("%d", &a);
    printf("Entered %d \n", a);
    system("pause");
}