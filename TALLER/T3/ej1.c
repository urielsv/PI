/*
 * Escribir un programa que lea un nuemro entero y obtenga la suma de las
 * cifras.
 * EJemplo:
 * Se lee 4351209
 * Muestra: 24
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

#define     DEC_BASE    10

int main()
{
    int num;
    num = getint("Escriba un numero");
    
    if (num < 0)
        num = -num;

    int sumaNum = 0;
    while ( num != 0 ) {
        sumaNum += num % DEC_BASE;
        num /= DEC_BASE;
    }
        printf("%d\n", sumaNum); 

    return 0;
}
