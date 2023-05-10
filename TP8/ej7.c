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
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FILS 30
#define COLS 30

typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB } Tdireccion;

typedef struct posicion {
    char * palabra;
    size_t fila;
    size_t columna;
    Tdireccion direccion;
} Posicion;

bool buscarDir(const char *palabra, char m[FILS][COLS], int i, int j, int row_delta, int col_delta) {
    for (size_t k = 0; palabra[k]; k++) {
        int row = i + k * row_delta;
        int col = j + k * col_delta;
        
        if (row < 0 || row >= FILS || col < 0 || col >= COLS || m[row][col] != palabra[k]) {
            return false;
        }
    }
    return true;
}

int busqueda(const char *palabra, char m[FILS][COLS], int i, int j, Tdireccion dirs[]) {
    int row_deltas[] = {0, 0, 1, -1, -1, 1, -1, 1};
    int col_deltas[] = {1, -1, 0, 0, -1, -1, 1, 1};

    int ctr = 0;

    for (int k = 0; k < 8; k++) {
        if (buscarDir(palabra, m, i, j, row_deltas[k], col_deltas[k])) {
            dirs[ctr++] = k;
        }
    }

    return ctr;
}

Posicion *resolverSopa(char m[FILS][COLS], char **dic) {
    size_t capacity = 10;
    Posicion *result = malloc(capacity * sizeof(Posicion));
    if (!result) {
        return NULL;
    }
    size_t size = 0;

    for (size_t d = 0; dic[d][0]; d++) {
        char *palabra = dic[d];

        for (int i = 0; i < FILS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (m[i][j] == palabra[0]) {
                    Tdireccion dirs[8];
                    int found = busqueda(palabra, m, i, j, dirs);

                    for (int k = 0; k < found; k++) {
                        /* Realojamos con crecimiento exponencial. */
                        if (size >= capacity) {
                            capacity *= 2;
                            Posicion *new_result = realloc(result, 
                                                    capacity * sizeof(Posicion));
                            if (!new_result) {
                                free(result);
                                return NULL;
                            }
                            result = new_result;
                        }
                        /* Otra forma seria utilizar bloques tal que:
                        if (size % BLOCK == 0) {
                            capacity += BLOCK;
                            Posicion *new_result = realloc(result, capacity * sizeof(Posicion));
                            if (!new_result) {
                                free(result);
                                return NULL;
                            }
                            result = new_result;
                        }
                        El problema de esto es que si el bloque es demasiado 
                        pequeno se harian demasiados realloc con mucha frecuencia.
                        */
                        result[size++] = (Posicion){.palabra = palabra, .fila = i, .columna = j, .direccion = dirs[k]};
                    }
                }
            }
        }
    }

    // Añadir el último elemento con palabra=NULL para marcar el final del vector
    if (size >= capacity) {
        Posicion *new_result = realloc(result, (++capacity) * sizeof(Posicion));
        if (!new_result) {
            free(result);
            return NULL;
        }
        result = new_result;
    }
    result[size] = (Posicion){.palabra = NULL, .fila = 0, .columna = 0, .direccion = 0};

    return result;
}
