// EX 1

int ex1a(int x)
{
    int y;
    y = -x-1;
    return y;
}

int ex1b(int x)
{
    int y;
    y = x*13;
    return y;
}

int ex1c(int x)
{
    int y;
    y = (x<7)?0:x;
    return y;
}

// EX 3

int X=1, Y;

template<typename T>

T ex3(T x)
{
    T y;
    y = -x-1;
    return y;
}

// EX 5

double ex5(double x)
{
    double y;
    y = -x-1;
    return y;
}

// EX 6


int ex6(int x)
{
    static int y;
    y = -x-1;
    return y;
}

int main()
{
    // Задание 1а и 4
    ex1a(1);
    // Задание 1б
    ex1b(1);
    // Задание 1в
    ex1c(1);

    // Задание 3
    Y = -X-1;

    ex3((char)1);
    ex3((short)1);
    ex3((long)1);
    ex3((long long)1);
    ex3((long double)1);

    // Задание 5

    ex5(999E-8);

    // Задание 6

    ex6(-1);

    return 0;
}