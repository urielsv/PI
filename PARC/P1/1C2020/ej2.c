/*
 * Escribir una función que reciba una matriz de números enteros y cuya cantidad 
 * de filas está dada por la constante simbólica FILS y la cantidad de columnas 
 * por la constante simbólica COLS.
 *
 * La función debe retornar 1 si la matriz es "ascendente", -1 si es "descendente" 
 * y 0 si no es ascendente ni descendente. 
 * Se dice que una matriz es ascendente si recorriendola en forma ordenada por filas 
 * cada elemento es mayor o igual al anterior, En forma análoga se define una matriz 
 * descendente.
 */

#include <stdio.h>

#define FILS    3
#define COLS    4

int matType(const int m[FILS][COLS]);

int main() 
{
    int m1[][COLS] = {{-6,-5,2,6},
                      {7,9,9,14},
                      {21,32,45,46}};
    int type = matType(m1);
    printf("%d", type); 
    
    int m2[][COLS] = {{19,13,12,8},
                      {7,7,5,-1},
                      {-6,-10,-14,-20}};
    type = matType(m2);
    printf("%d", type); 
    
    int m3[][COLS] = {{-6,-5,-6,6},
                      {7,9,10,14},
		              {21,32,45,46}};

    type = matType(m3);
    printf("%d", type); 

    int m4[][COLS] = {
		             {19,13,18,8},
		             {7,5,2,-1},
		             {-6,-10,-14}};
    type = matType(m4);
    printf("%d", type); 

    return 0;
}

int matType(const int m[FILS][COLS]) 
{
    int type = 0;
   
    int asc, des;
    asc = des = 1;
    int prev = m[0][0];
    for (int i = 0; i < FILS && (asc || des); i++) {
        for (int j = 1; j < COLS && (asc || des); j++) {
            int pos = m[i][j]; 
            
            if (asc && pos < prev) {
                asc = 0;
            } else if (des && pos > prev) {
                des = 0;
            }
            prev = pos;
        }
    }

    if (asc) {
        type = 1;
    } else if (des) {
        type = -1;
    } else {
        type = 0;
    }

    return type;
}

