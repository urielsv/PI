#include <stdio.h>

#define CUBO(x)  (x) * (x) * (x)

int cubo (int num);
int main(void)
{
    int a=4, b, c;
    b = CUBO(a+1);
    c = cubo(a+1);
    printf("%d, %d", b, c);
    return 0;
}

int cubo ( int num )
{
    return num * num * num;
}
