/*
 * Los laboratorios de Propulsión por Reacción tienen la representación del cielo y 
 * sus estrellas, digitalizada en una matriz bidimensional de hasta 80 columnas 
 * por 20 filas. Cada elemento de la misma representa la cantidad de luz que hay en 
 * una zona del cielo con un rango de intensidad entre 0 y 20. En el lugar de 
 * coordenadas (i,j) del cielo se considera que hay una estrella si el elemento Aij 
 * correspondiente  cumple con la siguiente relación:
 *
 * 	( A[i,j] + suma de las ocho intensidades circundantes ) / 9 > 10
 *
 * 	Escribir una función (en no más de 15 líneas) que reciba tres parámetros de 
 * 	entrada representando a una matriz de dichas características y sus dimensiones. 
 * 	Dicha función debe localizar gráficamente las estrellas en la pantalla representando 
 * 	las mismas con el carácter ‘*’. La función debe ignorar las aristas de la matriz.
 */

#include <stdio.h>

#define FILS 10
#define COLS 30

static int sumaCentro(const int cielo[][COLS], int f, int c);
void graficar(const int cielo[][COLS], int filas, int columnas);

int main (void) 
{
	int cielo1[FILS][COLS] = {{0}};

	puts("A continuación debe mostrar 8 filas en blanco");

	graficar(cielo1, FILS, COLS);
	puts("-----------------------------");

	
	int cielo2[FILS][COLS] = {
		{10, 17, 6, 15, 6, 7, 8, 9, 11, 12, 13, 15, 8, 10, 11, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 13, 11, 3, 9, 20},
		{18, 17, 6, 5, 6, 7, 8, 9, 11, 12, 13, 5, 8, 10, 1, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 13, 11, 3, 9, 20},
		{10, 15, 16, 15, 6, 17, 8, 19, 11, 12, 13, 1, 8, 10, 11, 1, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
		{12, 2, 6, 5, 16, 7, 8, 9, 1, 12, 13, 15, 8, 10, 1, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
		{8, 5, 4, 15, 6, 7, 8, 9, 12, 12, 13, 5, 8, 10, 11, 13, 14, 15, 18, 20, 11, 8, 12, 3, 12, 23, 11, 3, 9, 20},
		{20, 19, 18, 15, 16, 7, 8, 9, 11, 12, 13, 15, 18, 10, 11, 13, 14, 15, 18, 20, 11, 8, 12, 3, 12, 23, 11, 3, 9, 20},
		{10, 9, 9, 15, 16, 7, 8, 9, 12, 12, 13, 11, 8, 10, 1, 13, 14, 15, 18, 20, 11, 8, 2, 13, 12, 23, 11, 3, 9, 20},
		{10, 12, 9, 6, 16, 7, 8, 9, 15, 12, 13, 15, 18, 10, 11, 13, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
		{10, 7, 9, 15, 6, 7, 8, 9, 11, 12, 13, 15, 8, 10, 1, 10, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
		{10, 17, 16, 15, 6, 7, 8, 9, 11, 12, 13, 15, 8, 10, 11, 3, 14, 15, 18, 20, 11, 8, 2, 3, 12, 23, 11, 3, 9, 20},
	};

	puts("A continuación su función debe mostrar esto:");
	puts(" **     **      *****    *");
 	puts(" *              *****   ***");
	puts("         *      *****   ***");
	puts("   *     ****  ******   ***");
	puts(" ****    ***   ******   ***");
	puts(" ****   *****  ******   ***");
	puts("   *    *****   *****   ***");
	puts(" **     *****   *****   ***");

	puts("-----------------------------");
	puts("Y muestra esto:");
	graficar(cielo2, FILS, COLS);
	puts("-----------------------------");

	return 0;
}

#define ESTRELLAS 9
#define INTENSIDAD_MIN 10

void graficar(const int cielo[][COLS], int filas, int columnas)
{
    int suma = 0;
    for (int i = 1; i < filas-1; i++) {
        for (int j = 1; j < columnas-1; j++) {
            suma = sumaCentro(cielo, i, j); 
            if (suma / ESTRELLAS > INTENSIDAD_MIN ) {
                putchar('*');
            } else
                putchar(' ');
        }
        putchar('\n');
    }
}

static int sumaCentro(const int cielo[][COLS], int f, int c)
{
    return cielo[f-1][c-1] + cielo[f-1][c] + cielo[f-1][c+1] +
            cielo[f][c-1] + cielo[f][c] + cielo[f][c+1] +
            cielo[f+1][c-1] + cielo[f+1][c] + cielo[f+1][c+1];
}

