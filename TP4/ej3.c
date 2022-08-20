/*
 * Escribir, en no más de 5 líneas, un programa que defina y utilice
 * una macro con un parámetro para calcular el volumen de una esfera. 
 * El programa deberá calcular el volumen para esferas de radios de 
 * 1 a 10 cm., e imprimir los resultados en forma tabulada.    
 * Volumen de la Esfera = ( 4/3 ) * π * r3
 */

#include <stdio.h>

#define     PI      3.14
#define     VOL_ESFERA(r)       ((r > 0) && (r < 10) ? (4.0/3) * PI * ((r)*(r)*(r)) : 0.0)

int main()
{
    int r = 7;
    printf("%.2f", VOL_ESFERA(r));

    return 0;
}
