/*
 * Escribir un programa que utilice ciclos para imprimir 
 * la siguiente tabla de valores, para N desde 1 hasta 20. 
 * (En no más de 6 líneas)
 *       N  10*N    100*N   1000*N
 *       1  10      100     1000
 *       2  20      200     2000
 */

#include <stdio.h>

int main() 
{
    printf("N\t10*N\t100*N\t1000*N\n");

    for(int i = 1; i <= 20; i++) {
        printf("%d\t%d\t%d\t%d\n", i, i*10, i*100, i*1000);
    }

    return 0;
}
