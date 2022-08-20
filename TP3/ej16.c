/*
 * Ejercicio 16 - TP3
 * Autor: urielsv
 * Fecha: 10/08/22 (DD/MM/YY)
 *
 * Dado un número entero positivo, imprimir por salida 
 * estándar el equivalente en base binaria.
 *
 * El rango de números a considerar puede estar acotado. 
 * (En no más de 15 líneas).
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

#define     BIN_BASE    2
#define     DEC_BASE    10

int main()
{
   int num;
   int counter = 0;

   do {
       num = getint("Ingrese un numero decimal positivo: " );
   } while (num < 0);
    
   int aux = num;
   while ( aux != 0 ) {
        aux /= BIN_BASE;
        counter++;
   } 
   while ( counter > 0 ) {
        printf("%d", (num >> counter-1) % BIN_BASE);
        counter--;
   }

    return 0;
}
