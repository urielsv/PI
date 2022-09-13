/*
 * Escribir una función que compruebe si una solución dada a un Sudoku es correcta sabiendo que:
 * 
 * Un tablero sudoku se compone de una matriz de 9 filas por 9 columnas.
 * A su vez el tablero se subdivide en 9 subcuadrados de 9 casillas cada 
 * uno (3x3) NO SUPERPUESTOS (un número en una posición NO puede 
 * pertenecer a dos subcuadrados).
 *
 * Se debe verificar que todas las casillas contienen un número comprendido 
 * entre el 1 y el 9. Si alguna casilla contiene un número menor a 1 o mayor 
 * a 9, es incorrecta la matriz.
 *
 * Por fila, no hay valores repetidos
 *
 * Por columna, no hay valores repetidos
 *
 * Por subcuadrado, no hay valores repetidos
 */

// Repetidas (NO EN):
// Subcuadrado
// Linea.

#include <stdio.h>
#include <assert.h>

#define DIM 9

int sudokuSolver(char m[][DIM]);
static int checkFil(char m[][DIM], unsigned int f, unsigned char num);
static int checkCol(char m[][DIM], unsigned int c, unsigned char num);
static int checkSub(char m[][DIM], unsigned char f, unsigned char c, unsigned char num);
static int checkUnique(char m[][DIM], unsigned char f, unsigned char c, unsigned char num);

int main(void) {
  // Una matriz vacía no es solución
  char sudoku[DIM][DIM] = {{0}};

  assert(sudokuSolver(sudoku)==0);

  char sudoku2[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,2}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku2)==1);
  
  char sudoku3[DIM][DIM] = {
        {2,8,1,9,7,6,5,4,2}, 
        {3,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku3)==0);
  
  // Cuando se tomó este ejercicio en un parcial, en una de las respuestas
  // sólo chequeaban que la suma de cada fila, columna y cuadrado fuera 45
  char sudoku4[DIM][DIM] = {
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}, 
        {5,5,5,5,5,5,5,5,5}
  };

  assert(sudokuSolver(sudoku4)==0);

  char sudoku5[DIM][DIM] = {
        {3,8,1,9,7,6,5,4,12}, 
        {2,4,7,5,3,8,1,9,6},
        {5,6,9,2,1,4,8,7,3},
        {6,7,4,8,5,2,3,1,9},
        {1,3,5,7,4,9,6,2,8},
        {9,2,8,1,6,3,7,5,4},
        {4,1,2,6,8,5,9,3,7},
        {7,9,6,3,2,1,4,8,5},
        {8,5,3,4,9,7,2,6,1}
  };

  assert(sudokuSolver(sudoku5)==0);

  puts("OK!");
  return 0;
}

static int checkFil(char m[][DIM], unsigned int f, unsigned char num)
{
    /* Checkear fila, si es valida entonces devuelve 1 */
    int totNum = 0;
    for (int i = 0; i < DIM && totNum <= 1; i++) {
       if (m[f][i] == num) 
           totNum++;
    }
    
    if (totNum > 1)
        return 0;
    return 1;
}

static int checkCol(char m[][DIM], unsigned int c, unsigned char num)
{
    /* Checkear columna, si es valida entonces devuelve 1 */
    int totNum = 0;
    for (int i = 0; i < DIM && totNum <= 1; i++) {
       if (m[i][c] == num) 
           totNum++;
    }
    
    if (totNum > 1)
        return 0;
    return 1;
}

#define     SUBCUAD(x)          (((x) >= 0 && (x) < 3) ? 0 :\
                                 ((x) >= 3 && (x) < 6) ? 3 :\
                                 ((x) >= 6 && (x) < 9) ? 6 : 0)
#define     SUBDIM  DIM/3
static int checkSub(char m[][DIM], unsigned char f, unsigned char c, unsigned char num)
{
    /* Checkear subcuadrado, si es valido entonces devuelve 1 */

    int totNum = 0;
    for (int i = 0; i < SUBDIM && totNum <= 1; i++) {
        for (int j = 0; j < SUBDIM && totNum <= 1; j++) {
            int pFil = i + SUBCUAD(f);
            int pCol = j + SUBCUAD(c);
            if (m[pFil][pCol] == num) 
                totNum++; 
        }
    }
    if (totNum > 1)
        return 0;
    return 1;
}

int sudokuSolver(char m[][DIM])
{
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) { 
            int num = m[i][j]; 

            if (num <= 0 || num > 9)
                return 0;

            /* 
             * Preguntar si tengo que hacer esto en un if o 2 por el tema de no
             * cumplir una condicion -> tira return. 
             */

            if ((i % 3 == 0 && j % 3 == 0) && !checkSub(m, i, j, num))
                    return 0;

            if (!(checkFil(m, i, num) && checkCol(m, j, num)))
                return 0;
        }
    }

    return 1;
}
