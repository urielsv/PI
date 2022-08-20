/*
 * Escribir una función que reciba dos parámetros de entrada de tipo 
 * entero y devuelva en su nombre un número aleatorio entre ambos números. 
 * (En una línea)
 */

#include <stdio.h>
#include <stdlib.h>

static int randNum(int menor, int mayor)
{
    return  (rand() / ((double) RAND_MAX+1) * (mayor - menor + 1) + menor); 
    // o return (rand() % (mayor - menor + 1)) + menor;
}

int main()
{
    printf("%d", randNum(1,6));
    return 0;
}

