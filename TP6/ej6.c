/*
 * Dado un arreglo ordenado ascendentemente se pide escribir una 
 * función que reciba como parámetro de entrada/salida el arreglo 
 * y como parámetro de entrada su dimensión y que lo devuelva desordenado, 
 * simulando la mezcla de un mazo de cartas o de un bolillero 
 * (en no más de 10 líneas).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * shuffleArray(int arr[], unsigned int dim);
int main()
{
    srand(time(NULL));
    int arr[] = {1, 5, 9, 11, 15};
    shuffleArray(arr, 5);
    for (int i = 0; i < 5; i++) 
        printf("%d) %d\n", i, arr[i]);
    return 0;
}

int * shuffleArray(int arr[], unsigned int dim)
{
    int swap_pos, aux;
    for (int i = 0; i < dim ; i++) { 
        swap_pos = rand() % dim; 
        aux = arr[i];
        arr[i] = arr[swap_pos];
        arr[swap_pos] = aux;
    }
    return arr;
}
