/*
 * Escribir la función interseccion que reciba dos matrices m1 y m2 con igual 
 * cantidad de filas y columnas (dadas por las constantes simbólicas FILS y COLS), 
 * y una tercera matriz donde se guardará el resultado (también de dimensiones FILS y COLS). 
 * En cada fila i de la matriz resultado debe dejar -sin repetidos- la intersección 
 * de las flas i de las matrices m1 y m2. Si la cantidad de elementos resultantes 
 * es menor a COLS debe completar la fila con ceros.
 */

#include <stdio.h>

#define FILS    3
#define COLS    6

typedef unsigned int uInt;

void intr(const uInt m1[FILS][COLS], const uInt m2[FILS][COLS], uInt newMat[FILS][COLS]);
static void intrVect(const uInt v1[COLS], const uInt v2[COLS], uInt newVect[COLS]);
static int hasElem(uInt num, const uInt v[COLS]);

int main()
{
    uInt m1[FILS][COLS] = { 	{ 1, 2, 3, 4, 5, 6}, 
                            { 2, 1, 2, 1, 3, 1}, 
                            {10, 9, 4, 3,10, 5}};
	uInt m2[FILS][COLS] = { 	{ 6, 2, 1, 4, 5, 3},
                            { 1, 1, 2, 3, 3, 1},
                            { 1,19, 7, 8, 1,15}};
	uInt m3[FILS][COLS];

	intr(m1, m2, m3);

    for(int i = 0; i < FILS; i++) {
        for(int j = 0; j < COLS; j++) {
        printf("%d ", m3[i][j]);
        }
        puts("");
    }


    return 0;
}

void intr(const uInt m1[FILS][COLS], const uInt m2[FILS][COLS], uInt newMat[FILS][COLS]) 
{
    for(int i=0; i < FILS; i++) {
        intrVect(m1[i], m2[i], newMat[i]);
    }
}

/* Eliminar la pos y cambiarlo por vect */

// vector (fila) 3 --> m[3][i] 
static void intrVect(const uInt v1[COLS], const uInt v2[COLS], uInt newVect[COLS])
{
    int k = 0;
    for (int i = 0, appr = 0; i < COLS; i++, appr = 0) {
        for (int j = 0; j < COLS && !appr; j++) { /* Check reemp hasElem */
            if (v1[i] == v2[j]) {
                appr = 1;
            }
        }

        if (appr && !hasElem(v1[i], newVect)) { 
                newVect[k++] = v1[i];
        } else { /* No va, deben estar al final*/
                newVect[k++] = 0; 
        }
    }
}

static int hasElem(uInt num, const uInt v[COLS])
{
    int enc = 0;
    for (int i = 0; i < COLS && !enc; i++) {
             if (v[i] == num) {
                enc = 1;
             }
        }
    return enc;
}
