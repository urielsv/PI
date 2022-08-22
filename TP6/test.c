#include <stdio.h>

int main()
{
    int x = -3;
    int y = 12;
    int *px, *py;
     
    px = &x;
    py = &y;
    (*px)++;
    *py = 50;
    *px = *py; 
    px = py;
    (*px)++;
    printf("%d, %d", *px, *py);
    return 0;
}
