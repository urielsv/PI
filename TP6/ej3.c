/*
 * Difficulty: **_
 * Dado un arreglo lineal de números reales, cuyo indicador de fin de elementos es 
 * cero, escribir una funcion para obtener la mayor diferencia entre dos elementos 
 * consecutivos. (En no mas de 5 lineas). Tener en cuenta que los numeros pueden 
 * ser negativos. En caso de que el vector tenga un solo elemento debera retornar 
 * como diferencia el valor cero.
 *
 * A partir de ahora, cuando escriban sus propias funciones y consideren que los 
 * arreglos que recibas como parametros de entrada no deben ser alterados en el 
 * cuerpo de la funcion, no se olviden de colocar el calificador const.
 */
#include <stdio.h>
#include <math.h>

double mayDiff(const double []);
int main() 
{
    double nums[] = {3.5, 4.7, -2.0, 9.0, 3, 0, 15};
    printf("Mayor diferencia: %.2f\n", mayDiff(nums));
    return 0;
}

// Por enunciado no contemplo el caso de elementos despues de un 0.
#define EPSILON     0.000001
double mayDiff(const double arr[])
{
    double diff = 0, aux = 0;
    for (int i = 0; fabs(arr[i]) > EPSILON;i++) {
        if (fabs(arr[i] - arr[i+1]) > aux)
                aux = fabs(arr[i] - arr[i+1]);
    }
    return aux;
}
#undef EPSILON
