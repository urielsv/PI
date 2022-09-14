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

int maxFil(int m[FIL][COL]);

int main() {
    int m1[FIL][COL] = { { 16,3,2,13},
                         { 5,10,11,8},
                         { 9,6,7,12},
                         { 4,15,14,1}};
    
    int m2[FIL][COL] = { { 1,3,2,5},
                         { 5,0,1,8},
                         { 9,6,7,2},
                         { 4,5,4,1}};
    int test1 = maxFil(m1);
    int test2 = maxFil(m2);
    assert(test1==-1);
    assert(test2==9672);
    puts("OKI!");
    return 0;
}



int maxFil(int m[FIL][COL]) 
{
    /* Checkear fila valida y mayor y retornarla */ 
    int num = -1;
    for (int i = 0, suma = 0; i < FIL; i++, suma = 0) {
        
        for (int j = 0, pot = 1, valid = 1; j < COL && valid; j++) {
     
            if (!(m[i][j] >= 0 && m[i][j] <= 9)) {
                valid = 0;
                suma = num;
            } else {
                suma += m[i][(COL-1)-j] * pot;
                pot *= 10;
            }
        }

        if (suma > num) 
            num = suma;
        
    }
    return num;
}
