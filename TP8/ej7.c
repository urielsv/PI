/*
 * Se desea escribir una función para resolver una sopa de letras. 
 * Una sopa de letras se representa como una matriz de char de FILS filas y COLS columnas, 
 * donde FILS y COLS son constantes previamente definidas. Se cuenta además con un vector 
 * ordenado que contiene las palabras a buscar, donde cada elemento es un string constante, 
 * y como marca de final contiene el string vacío.
 *
 * (Mas info en el TP8).
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define COLS 7
#define FILS 6


typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB} Tdireccion;

struct posicion {
    char * palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
};

// NOTA: depende del orden en que realizan la busqueda, el testeo puede dar diferente
//       en esta prueba asumimos que se recorre el diccionario, y cada palabra se busca en la sopa de 
//       letras.
//.      Si en vez de hacerlo así recorren la matriz y por cada letra buscan si hay una palabra en el diccionario
//       que empiece con esa letra, tienen que cambiar el testeo para que coincida con el orden en que se encuentran.

struct posicion * resolverSopa(char ** dic, char m[FILS][COLS]);
int busqueda(char * palabra, char m[FILS][COLS],int i, int j, int dirs[]);
int buscarDir(char * palabra, char m[FILS][COLS], int i, int j, int dirX, int dirY);

int main(void) {
  char * diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};
   
  char sopa[FILS][COLS] =
     {{'X','X','X','O','X','X','X'},
      {'A','P','A','C','Y','Y','O'},
      {'Z','E','Z','R','Z','C','X'},
      {'E','R','R','O','R','X','X'},
      {'X','R','I','O','I','E','X'},
      {'X','O','X','X','O','X','X'}};
  
  struct posicion * res = resolverSopa(diccionario, sopa);
  // La cantidad de palabras encontradas debe ser 9
  int expected = 9;
  int count = 0;
  while ( res[count].palabra != NULL)
     printf("%s\n", res[count++].palabra);
  assert(count == expected);

  assert(strcmp(res[0].palabra,"ARRE")==0);
  assert(res[0].fila==1);
  assert(res[0].columna==2);
  assert(res[0].direccion==D_AB);

  assert(strcmp(res[3].palabra,"ORCO")==0);
  assert(res[3].fila==3);
  assert(res[3].columna==3);
  printf("%d\n", res[3].direccion);
  assert(res[3].direccion==ARR);
  
  assert(strcmp(res[4].palabra,"ORCO")==0);
  assert(res[4].fila==4);
  assert(res[4].columna==3);
  assert(res[4].direccion==D_AR);

  assert(strcmp(res[6].palabra,"REA")==0);
  assert(res[6].fila==3);
  assert(res[6].columna==2);
  assert(res[6].direccion==I_AR);

  puts("OK");
  return 0;
}

#define BLOCK   5
struct posicion * resolverSopa(char ** dic, char m[FILS][COLS])
{
    struct posicion * resp = NULL;
    char * palabra;
    int dirs[D_AB+1];
    int ctr_dirs, dir;
    int t = 0;

    for (int i = 0; dic[i][0]; i++) { // Check que no sea el string vacio.
        palabra = dic[i]; // Primera palabra.
        for (int j = 0; j < FILS; j++) {
            for (int k = 0; k < COLS; k++) {
               if (m[i][j] == palabra[0]) { // Si coinciden la primera entonces busco en direcciones.
                    ctr_dirs = busqueda(palabra, m, j, k, dirs);
                                           
                    for (dir = 0; dir < ctr_dirs; dir++) {
                        if (t % BLOCK == 0) {
                            resp = realloc(resp, (t + BLOCK + 1) * sizeof(*resp));
                        }
                        struct posicion ans = {palabra, i, j, dirs[dir]};
                        resp[t++] = ans;
                    }
               }
            }
        }
    }
    if (resp == NULL)
        resp = malloc(sizeof(*resp));
    struct posicion fin = {NULL, 0, 0, 0};
    resp[t++] = fin;
    resp = realloc(resp, t * sizeof(*resp));
    
    return resp;
}
#undef BLOCK
int busqueda(char * palabra, char m[FILS][COLS],int i, int j, int dirs[])
{
    int ctr = 0;
    if (buscarDir(palabra, m, i, j, 0, 1))
       dirs[ctr++] == DER;
    if (buscarDir(palabra, m, i, j, 0, -1))
       dirs[ctr++] == IZQ;
    if (buscarDir(palabra, m, i, j, 1, 0))
       dirs[ctr++] == ABA;
    if (buscarDir(palabra, m, i, j, -1, 0))
       dirs[ctr++] == ARR;
    if (buscarDir(palabra, m, i, j, -1, -1))
       dirs[ctr++] == I_AR;
    if (buscarDir(palabra, m, i, j, 1, -1))
       dirs[ctr++] == I_AB;
    if (buscarDir(palabra, m, i, j, -1, 1))
       dirs[ctr++] == D_AR;

   return ctr;

}

int buscarDir(char * palabra, char m[FILS][COLS], int i, int j, int dirX, int dirY)
{
    int len = strlen(palabra);
    int k = 0;
    for (; k < len && i >= 0 && j >=0 && i < FILS && j < COLS; k++) {
        if (palabra[k] != m[i][j]) 
            return 0;
      // Vi por la solucion que se incrementa para el lado que estamos evaluando en la fn "busqueda".
      i += dirX;
      j += dirY;
    }
    return k == len;
}
