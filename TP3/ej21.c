/*
 * Escribir un programa que lea un número entero, y 
 * escriba por salida estándar dicho número y un 
 * cartel indicando si es capicúa o no. 
 * (En no más de 10 líneas).
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

#define     DEC_BASE        10

int main() 
{
    int num;
    
    do {
    num = getint("Ingrese un numero entero: ");
    } while ( num < 0 ); 

    int capiNum = 0;
    int aux = num;

    while ( aux != 0 ) {  
        capiNum = capiNum * DEC_BASE + (aux % DEC_BASE);
        aux /= DEC_BASE;
    } printf("%s\n", (capiNum == num) ? "Es capi" : "No es capi :(");
    return 0;
}
