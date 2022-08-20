/*
 * La siguiente función intenta ser una instrumentación del algoritmo de Euclides 
 * para calcular el MCD de dos números, pero no siempre da el resultado correcto. 
 * Indicar errores y corregirlos para que funcione correctamente.
 *
 * Errores: auxi no definido.
 *          no retorna el mcd.
 *  
 */

#include <stdio.h>

int dcm (int a, int b)
{
    int auxi = a;
    while (auxi>0) {    
        a = b;
        b = auxi;
        auxi = a % b ;
    }
    return b;
}

int main()
{
    printf("%d", dcm(4585,2100));
    return 0;
}
