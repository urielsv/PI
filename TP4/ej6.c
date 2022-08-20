/*
 * Escribir la macro MAXIMO3 para determinar el mayor de 3 valores, usando la macro 
 * definida en el ejercicio anterior. (En no más de 10 líneas). 
 * Verificar su funcionamiento invocándola desde un programa.
 */

#include <stdio.h>

#define     MAXIMO3(x,y,z,max)      max = (x>y && x>z) ? x : ((y>z ? y : z))

int main() 
{
    int a = -50000, b = -500, c = -7000;
    int max;
    MAXIMO3(a,b,c,max);
    printf("%d", max);
    return 0;
}
