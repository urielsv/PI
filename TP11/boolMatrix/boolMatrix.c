#include "boolMatrix.h"
#include <stdlib.h>

typedef struct tCol {
    unsigned long col;
    struct tCol * tail;
} tCol;

typedef struct tRow{
    unsigned long row;
    struct tRow * tail;
    tCol * firstCol;
} tRow;

typedef struct boolMatrixCDT {
    tRow * firstRow;
} boolMatrixCDT;

boolMatrixADT newMatrix(void) {
    return calloc(1, sizeof(boolMatrixCDT));
}

static void freeColumns(tCol * col) {
    if ( col != NULL) {
        freeColumns(col->tail);
        free(col);
    }
}

static void freeRows(tRow * row) {
    // Hay que liberar las columnas de esta fila y el resto de las filas
    if( row != NULL) {
        freeColumns(row->firstCol);
        freeRows(row->tail);
        free(row);
    }
}


void freeBoolMatrix(boolMatrixADT m) {
    freeRows(m->firstRow);
    free(m);
}

static tCol * deleteCol(tCol * first, unsigned long col) {
    if ( first == NULL || first->col > col) {
        return first;
    }
    if ( first->col == col ) {
        tCol * aux = first->tail;
        free(first);
        return aux;
    }
    // col es mayor al primero, estará en la sublista ?
    first->tail = deleteCol(first->tail, col);
    return first;
}

static tRow * deleteInRow(tRow * first, unsigned long row, unsigned long col) {
    if(first == NULL || first->row > row) {
        return first;
    }
    if(first->row == row) {
        first->firstCol = deleteCol(first->firstCol, col);
        // Si la fila quedo sin columnas, eliminamos ese nodo
        if ( first->firstCol == NULL) {
            tRow * aux = first->tail;
            free(first);
            return aux;
        }
    }
    first->tail = deleteInRow(first->tail, row, col);
    return first;
}

void setTrue(boolMatrixADT m, unsigned long row, unsigned long col) {
    // Borra el nodo con row si  col era el único elemento de la fila
    m->firstRow = deleteInRow(m->firstRow, row, col);
}

static tCol * addCol(tCol * first, unsigned int col) {
    if (first == NULL || first->col > col) {
        tCol * aux = malloc(sizeof(*aux));
        aux->col = col;
        aux->tail = first;
        return aux;
    }
    if (first->col < col) {
        first->tail = addCol(first->tail, col);
    }

    return first;
}

static tRow * addRow(tRow * first, unsigned long row, unsigned long col) {
    if ( first == NULL || first->row > row) {
        tRow * aux = malloc(sizeof(*aux));
        aux->row = row;
        aux->tail = first;
        aux->firstCol = addCol(aux->firstCol, col);
        return aux;
    }
    if (first->row < row) {
        first->tail = addRow(first->tail, row, col);
    }

    return first;
}

void setFalse(boolMatrixADT m, unsigned long  row, unsigned long col) {
    m->firstRow = addRow(m->firstRow, row, col);
}

static int getCol(tCol * first, unsigned long col) {
    if (first == NULL)
        return 0;

    if (first->col == col)
        return 1;

    return getCol(first->tail, col);
}

static int getRow(tRow * first, unsigned long row, unsigned long col) {
    if (first == NULL)
        return 0;

    if (first->row == row) 
        return getCol(first->firstCol, col);
    
    return getRow(first->tail, row, col);
}

int get(const boolMatrixADT m, unsigned long row, unsigned long col) {
    return getRow(m->firstRow, row, col);
}


