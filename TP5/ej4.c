/*
 * Escribir una función que reciba dos parámetros de entrada de tipo 
 * entero y devuelva en su nombre un número aleatorio entre ambos números. 
 * (En una línea)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static double randNum(int menor, int mayor)
{
    return  (rand() / ((double) RAND_MAX+1) * (mayor - menor + 1) + menor); 
    // o return (rand() % (mayor - menor + 1)) + menor;
}
#define MAY_VAL 1
#define MIN_VAL 0
int main()
{
    srand(time(NULL));
    double lol = rand()/ ((double) RAND_MAX+1) * (MAY_VAL - MIN_VAL) + MIN_VAL;
    printf("%f", lol);
    return 0;
}

