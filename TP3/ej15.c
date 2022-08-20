/*
 * Dado un entero que representa un número binario positivo 
 * (todos sus dígitos son cero o uno), imprimir por salida e
 * stándar el equivalente decimal. (En no más de 10 líneas).
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

#define     DEC_BASE    10
#define     BIN_BASE    2

int main() 
{
    unsigned int bin;
    bin = getint("Binario: ");
    
    int last_num = 0; 
    int bin_sum = 0;
    
    for (int i=0; bin != 0; i++) {
        last_num = bin % BIN_BASE; 
        bin_sum += (last_num * (1 << i)); 
        bin /= DEC_BASE;
    } printf("Decimal: %d\n", bin_sum);
        
    return 0;
}
