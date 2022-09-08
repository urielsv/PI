/*
 * Escribir una función que realice el producto de dos matrices cuadradas y 
 * lo devuelva en una tercera. El algoritmo de la función que realiza el producto 
 * no debe tener más de dos ciclos for anidados explícitamente, pero sí puede 
 * utilizar funciones auxiliares que contengan ciclos 
 * (Ninguna de las funciones debe superar las 5 líneas).
 */

#include <stdio.h>
#include <assert.h>

#define DIMMAX 4

void
productoMat( const int m1[][DIMMAX], const int m2[][DIMMAX], int m3[][DIMMAX], int dim);
static 
int rowxCol(const int m1[][DIMMAX], const int m2[][DIMMAX], int row, int col, int dim);

int main(void) 
{
  int m1[DIMMAX][DIMMAX] = {
      { 1, 2, 3, 4},
      {11,12,13,14},
      {21,22,23,24},
      {31,32,33,34},
      };

  int m2[DIMMAX][DIMMAX] = {
      { 2, 1, 3, 4},
      { 3, 4, 5, 2},
      { 2, 5,10,11},
      {21,12,13,14},
      };

  int ceros[DIMMAX][DIMMAX] ={{0}};

  int m3[DIMMAX][DIMMAX];

  productoMat(m1, ceros, m3, DIMMAX);

  for(int i=0; i < DIMMAX; i++) {
    for(int j=0; j < DIMMAX; j++)
      assert(m3[i][j]==0);
  }

  // Ahora ceros para a ser I
  for(int i=0; i < DIMMAX; i++) {
    ceros[i][i] = 1;
  }
  productoMat(m1, ceros, m3, DIMMAX);
  for(int i=0; i < DIMMAX; i++) {
    for(int j=0; j < DIMMAX; j++)
      assert(m3[i][j]==m1[i][j]);
  }

  int res[][DIMMAX] = {
    {98,72,95,97},
    {378,292,405,407},
    {658,512,715,717},
    {938,732,1025,1027}
  };

  productoMat(m1, m2, m3, DIMMAX);
  for(int i=0; i < DIMMAX; i++) {
    for(int j=0; j < DIMMAX; j++)
      assert(m3[i][j]==res[i][j]);
  }
  printf("OK!\n");
}

static int rowxCol(const int m1[][DIMMAX], const int m2[][DIMMAX], int row, int col, int dim)
{
    int v = 0;
    for (int i = 0; i < dim; i++) {
        v += m1[row][i]*m2[i][col]; 
        }
    return v; 
}
void productoMat( const int m1[][DIMMAX], const int m2[][DIMMAX], int m3[][DIMMAX], int dim)
{
   for ( int i = 0; i < dim; i++) {
     for (int j = 0; j < dim; j++) {
        m3[i][j] = rowxCol(m1, m2, i, j, dim);
     }
   }
}

