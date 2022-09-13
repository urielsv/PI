/*
 * Escribir una función que, dada una matriz de enteros de N filas y M columnas,
 * arme los números que se forman con cada fila y retorne cuál es el máximo.
 * Para poder armar un número con los elementos de una fila,
 * todos sus elementos deben contener un número entero entre 0 y 9 inclusive.
 * Si hubiera números negativos o de más de una cifra, no se completa el armado del número.
 * Si no se pudo armar ningún número, retorna -1.
 */
#include <stdio.h>
#include <assert.h>

#define FIL     4
#define COL     4

int valMax(int m[FIL][COL], int v[FIL]);
static int crearVec(int m[FIL][COL], int v[]);
static int crearElem(int v[COL]);

int main() {
    int m1[FIL][COL] = { { 16,3,2,13},
                         { 5,10,11,8},
                         { 9,6,7,12},
                         { 4,15,14,1}};
    
    int m2[FIL][COL] = { { 1,3,2,5},
                         { 5,0,1,8},
                         { 9,6,7,2},
                         { 4,5,4,1}};
    int vec[COL];
    int test1 = valMax(m1, vec);
    int test2 = valMax(m2, vec);
    assert(test1==-1);
    assert(test2==9672);
    puts("OKI!");
    return 0;
}

static int crearElem(int v[COL])
{
    /* Crear elemento para vector */
    int suma = 0;
    for (int i = 0, pot = 1; i < COL ; i++) { 
                suma += v[(COL-1)-i] * pot;
                pot *= 10;
    } 
    return suma;
}

static int crearVec(int m[FIL][COL], int v[FIL]) 
{
    /* Guarda elementos validos en vector */
    int k = 0;
    for (int i = 0, valid = 1; i < FIL && valid; i++, valid = 1) {
        
        for (int j = 0, pot = 1; j < COL && valid; j++) {
            if (!(m[i][j] >= 0 && m[i][j] <= 9))
                valid = 0;
        }

        if (valid) {
            v[k++] = crearElem(m[i]);
        } 
    }
    return k;
}

int valMax(int m[FIL][COL], int v[FIL])
{
    /* Evalua el elemento mas grande del vector */
    int max = -1;
    
    int dim = crearVec(m, v);

    for (int i = 1; i < dim; i++) {
        if (v[i] > v[i-1])
            max = v[i];
    }

    return max;
}
