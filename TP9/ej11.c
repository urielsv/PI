/*
Ejercicio 11
    Escribir una función que reciba cuatro parámetros: 
    Matrix:  parámetro de entrada-salida que representa una matriz cuadrada booleana 
    Dim: parámetro de entrada de tipo entero que representa la dimensión de la matriz 
    Fila: parámetro de entrada de tipo entero que representa un número de fila de la mat.
    Columna: parámetro de entrada de tipo entero que representa un número de columna 
    de la matriz

 	La función se encargará de devolver dicha matriz cambiada de la siguiente forma:  
    el elemento de la fila y columna indicada y todos los de las dos diagonales que 
    pasen por él se reemplazarán por su negación booleana, los demás elementos de la 
    matriz quedan igual.
*/

#include <stdio.h>
#include <assert.h>

#define MAX 10

void rDiag(int m[][MAX], int dim, int fil, int col, int dirX, int dirY) 
{
    if (fil < 0 || fil > dim-1 || col < 0 || col > dim-1) return;
    else {
        m[fil][col] = (m[fil][col]) ? 0 : 1;
        rDiag(m, dim, fil + dirX, col + dirY, dirX, dirY);
    }
}
void reemplazo(int m[][MAX], int dim, int fil, int col)
{
    rDiag(m, dim, fil-1, col-1, -1, -1);
    rDiag(m, dim, fil+1, col+1, 1, 1);
    rDiag(m, dim, fil-1, col+1, -1, 1);
    rDiag(m, dim, fil+1, col-1, 1, -1);
    m[fil][col] = (m[fil][col]) ? 0 : 1;
}

int main(void) {

  int m[5][MAX] = { {1,0,1,0,1},
                    {0,1,1,1,1},
                    {1,0,0,1,0},
                    {1,1,1,0,1},
                    {0,0,0,0,0}};
  reemplazo(m, 5, 1, 2);
  int m2[5][MAX] = { {1,1,1,1,1},
                    {0,1,0,1,1},
                    {1,1,0,0,0},
                    {0,1,1,0,0},
                    {0,0,0,0,0}};
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);
  reemplazo(m, 5, 1, 2);
  reemplazo(m, 5, 1, 2);
  for(int i=0; i < 5; i++)
     for(int j=0; j<5; j++)
        assert(m[i][j]==m2[i][j]);

  printf ("OK!\n");
  return 0;
}