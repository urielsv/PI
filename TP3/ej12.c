/*
 * Escriba enunciados for que impriman las siguientes secuencias de valores:
 * a) 3,8,13,18,23
 * b) 20,14,8,2,-4,-10
 * c) 19,27,35,43,51
 */

#include <stdio.h>

int main()
{
    int i;
    for(i=3; i<=23; i+=5) 
        printf("%d\n", i); 
    for(i=20; i>=-10; i-=6)
        printf("%d\n", i);
    for(i=19; i<=51; i+=8)
        printf("%d\n", i);

    return 0;
}
