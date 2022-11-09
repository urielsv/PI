#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "utillist.h"

TList restaList(TList l1, TList l2);

#define ELEMS 200

int main(void)
{
    int pares[ELEMS], impares[ELEMS];

    for(int i=1; i <= ELEMS; i++) {
      pares[i-1] = i * 2 ;
      impares[i-1] = i * 2 - 1;
    }

    TList lPar = fromArray(pares, ELEMS);
    TList lImpar = fromArray(impares, ELEMS);

    TList lPar2 = restaList(lPar, lImpar);
    assert(checkElems(lPar2, pares, ELEMS));
    // Verificamos ademas que no sean los mismos nodos
    assert(lPar2 != lPar);
    assert(lPar2->tail != lPar->tail);
    freeList(lPar2);
    freeList(lPar);
    freeList(lImpar);

    int all[ELEMS * 2];
    for(int i=1, j=0; i <= ELEMS; i++) {
      all[j++] = i * 2 - 1;
      all[j++] = i * 2 ;
    }
    TList lAll = fromArray(all, ELEMS * 2);
    lPar = fromArray(pares, ELEMS);
    TList lImpar2 = restaList(lAll, lPar);
    assert(checkElems(lImpar2, impares, ELEMS));
    freeList(lPar);

    lPar = restaList(lAll, lImpar2);
    assert(checkElems(lPar, pares, ELEMS));
    freeList(lPar);
    freeList(lAll);
    
    lPar = NULL;
    lImpar = fromArray(impares, ELEMS);
    TList aux = restaList(lPar, lImpar);
    assert(aux == NULL);
    freeList(lImpar);

    aux = restaList(lImpar2, lImpar2);
    assert(aux == NULL);
    freeList(lImpar2);

    printf ("OK!\n");
    return 0;
}

TList restaList(TList l1, TList l2)
{
    if (l1 == NULL) return NULL;

    if (l2 == NULL || l2->head > l1->head) {
        TList aux = malloc(sizeof(*aux));
        aux->head = l1->head;
        aux->tail = restaList(l1->tail, l2);
        return aux;
    }

    if (l1->head > l2->head) return restaList(l1, l2->tail);

    return restaList(l1->tail, l2->tail);
}
