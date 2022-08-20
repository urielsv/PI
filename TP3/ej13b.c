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

    for(int i=1; i<=lados*lados; i++){  
        printf("*");
        if(i % lados == 0) {
            printf("\n");
        } 
    }
    return 0;
}
