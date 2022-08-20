/* 
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
    //-- Dec to Bin
    unsigned long dec;
    dec = getlong("Decimal: "); 
    
    int dec_rem = 0; 
    while( dec != 0 ) { 
        dec_rem = dec % BIN_BASE; 
        dec /= BIN_BASE;
        printf("%d", dec_rem); // !! esta al revez (el print)
    } 
    
    return 0;
} // !! ESTA MAL !! LO HICE AL REVEZ POR NO ACOTAR CNATIDAD MAX.
