/*
 * Ejercicio 16 - Ejercicio de Parcial - TP4
 * Autor: urielsv
 *
 * Escribir la macro DIVISOR que reciba dos números enteros (no necesariamente positivos) 
 * y retorne 1 si el segundo es 
 * divisor del primero y cero si no es divisor. No usar funciones auxiliares.
 * Ejemplos de invocación:
 *
 * int a, b = 10, c = 3; 
 * a = DIVISOR(b,c);        a = 0 
 * a = DIVISOR(b,c-1);      a = 1 
 */

#include <stdio.h>

#define     DIVISOR(x,y)        (((x) < 0) && ((y) > 0)) ? (-(x) % (y) == 0 ) :\
                                    (((x) > 0) && ((y) < 0)) ? ((x) % -(y) == 0) :\
                                        ((x) % (y) == 0) 

int main()
{
    int a, b = 10, c = 3;
    a = DIVISOR(-15,3);
    printf("%d\n", a);
    return 0;
}
