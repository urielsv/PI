/*
 * Reescribir el ejercicio 17 del TP 04 utilizando funciones de la biblioteca estándar.
 */

#include <stdio.h>
#include <stdlib.h>

#define     ELAPSED(h1,m1,h2,m2)        (abs(h1-h2)*60 + (m1-m2))
int main()
{
    printf("%d\n", ELAPSED(3,10,2,15)); 
    return 0;
}
