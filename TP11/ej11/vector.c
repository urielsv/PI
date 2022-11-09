#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

/* Lo vi en la solucion xd. */
struct vectorCDT {
    elemType * values;
    char * isEmpty;
    size_t dim;
    size_t used;
    compare cmp;
};

/* Crear nuevo vector inicializado en 0. */
vectorADT newVector(compare cmp)
{
    vectorADT v = calloc(1, sizeof(vectorADT));
    v->cmp = cmp;
    return v;
}

void freeVector(vectorADT v)
{
    if (v != NULL) {
        free(v->values);
        free(v->isEmpty);
    }
    free(v);
}

int put(vectorADT v, elemType * elems, size_t dim, size_t index)
{
    if (elems == NULL) return 0; 

    /* Si el index del vector + dim de los elementos es mayor a la dimension del
     * TAD entonces agrego mas memoria. */
    if (dim+index > v->dim) {
        v->values = realloc(v->values, (dim + index) * sizeof(elemType));
        v->isEmpty = realloc(v->isEmpty, (dim + index) * sizeof(char));

        /* A los nuevos que agregue los seteo como libres. */
        for (size_t i = v->dim; i < dim + index; i++) {
                v->isEmpty[i] = 1;
        }

        /* Modifico la nueva dim. */
        v->dim = dim + index;
    }

    /* Empiezo el contador de v en index y lo continuo hasta la "nueva" dim. */
    int ctr = 0;
    for (int i = index, j = 0; i < index+dim; i++) {
        if (v->isEmpty[i]) {
            v->values[i] = elems[j++];
            v->isEmpty[i] = 0;
            v->used++;
            ctr++;
        }
    }
    return ctr;
}

int getIdx(vectorADT v, elemType elem)
{ 
    for (size_t i = 0; i < v->dim; i++) {
        
        /* Si no es una pos vacia y son iguales. */
        if (!v->isEmpty[i] && v->cmp(v->values[i], elem) == 0)
            return i;
    }

    /* Si no se encontro retorno -1. */
    return -1;
}

void deleteElement(vectorADT v, size_t index)
{
    if (index >= v->dim) return;

    /* el eliminar ES:
     * que se pueda pisar (porque tiene isEmpty).
     * No me importa que tenga basura. 
     */
    if (!v->isEmpty[index]) {
        v->isEmpty[index] = 1;
        v->used--;
    }
}

int elementCount(vectorADT v)
{
    return v->used; 
}


