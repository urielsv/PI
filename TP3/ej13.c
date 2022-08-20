/*
 * Dada una variable entera que indica el lado de un cuadrado, 
 * imprimir por salida estándar dicho cuadrado en forma de asteriscos.
 * a) Resolverlo con dos ciclos anidados.
 * b) Resolverlo con un único ciclo for.
 * 
 * Ejemplo: si el lado es 5, debe imprimir lo siguiente:
 * 
 *  *****
 *  *****
 *  *****
 *  *****
 *  *****
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

int main()
{    
    int lados;
    lados = getint("");
    
    int counter = 1; 
    int l_counter = 1;

    while (l_counter <= lados) {
        while (counter <= lados) {
            printf("*");
            counter++;
        } 
        printf("\n");
        counter = 1;
        l_counter++;
    }
    
    return 0;
}
