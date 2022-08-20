/*
 * Modificar el programa anterior para que lea un número decimal y sume los
 * dígitos de la parte decimal. Utilizar la función getfloat de la librería getnum
 * provista por la cátedra.
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

#define     DEC_BASE    10
#define     EPSILON     0.000000001
int main()
{
    float num;
    num = getfloat("Escriba un numero");
    
    if (num < 0)
        num = -num;

    int sumaNum = 0;
    float dec_p = (num) - num;
    while ( dec_p <= EPSILON ) {
        dec_p *= DEC_BASE;
        sumaNum += (int) dec_p;
        dec_p /= DEC_BASE;
    }
    printf("%d\n", sumaNum); 

    return 0;
}
