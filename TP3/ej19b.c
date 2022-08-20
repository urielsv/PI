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
#define     EPSILON     0.00000001
int main()
{
    double num;
    unsigned int ctr_bef = 0; 
    unsigned int ctr_aft = 0;
    int aux1;
    double dec_point;

    num = getdouble("");
    
    if( num < 0 ) 
        num = -num; 
    
    // Contador antes de coma.
    aux1 = (int) num;
    while ( aux1 != 0 ) {
        if ( (aux1 % DEC_BASE) == MATCH) 
            ctr_bef++;
        aux1 /= DEC_BASE;
    } printf("#5 (ANTES): %d\n", ctr_bef);
    
    // Contador despues de la coma
    dec_point = num - (int) num;
    while ( num - dec_point >= EPSILON ) { 
       
        dec_point *= DEC_BASE;
   
        if( ((int) dec_point % DEC_BASE) == MATCH ) {
            ctr_aft++;
        }

    } printf("#5 (DESPUES): %d\n", ctr_aft);

    return 0;
}
