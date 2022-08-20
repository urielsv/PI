/*
 * Leer un número entero e indicar cuántos dígitos de ese 
 * número son iguales a 5. Repetir para el caso de ser un 
 * número real, indicando cuántos 5 tiene en su parte entera y
 * cuántos en su parte decimal. 
 * (En no más de 10 líneas el primer caso, 
 * y no más de 25 el segundo caso).
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

#define     MATCH       5
#define     DEC_BASE    10

int main()
{
    long num;
    unsigned int counter = 0;

    num = getlong("");
    
    if( num < 0 ) 
        num = -num;

    while( num != 0 ) {
        if ( (num % DEC_BASE) == MATCH )
            counter++;
        num /= DEC_BASE;
    } printf("%d", counter);

    return 0;
}
