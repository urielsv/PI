/*
 * Escriba un programa que lea un entero no negativo 
 * ( cero o mayor ) y que calcule e imprima su factorial. 
 * En caso de ingresar un valor inválido, imprimir un cartel
 * aclarando cuáles son los valores válidos. 
 * (En no más de 10 líneas)
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

int main() 
{
    int num1;
    unsigned int fact = 1;
    
    do { 
    num1 = getint("Escriba un numero entero positivo: ");
    } while (num1 < 0); 

    for(int i=1; i <= num1; i++)
       fact *= i;
    printf("%d\n", fact);
    return 0;
}
