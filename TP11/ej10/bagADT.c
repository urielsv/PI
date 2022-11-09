#include "bagADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    elemType elem;
    unsigned int count;
    struct node * tail;
} TNode;

typedef TNode * TList;

struct bagCDT {
    TList first;
    unsigned int size;
};

bagADT newBag()
{
    return calloc(1, sizeof(struct bagCDT));
}

void freeBag(bagADT bag)
{
    /* Recorro con el actual. */
    TList curr = bag->first;
   
    /* Mientras que hayan nodos recorro y voy liberando. */
    while (curr != NULL) {
        TList aux = curr->tail;
        free(curr);
        curr = aux;
    }

    free(bag);
}

static TList addRec(TList first, elemType thisElem, unsigned int * ctr)
{
    int cmp;
    /* Caso 1: primera vez (first == NULL) o thisElem < first->elem. */
    if (first == NULL || (cmp = compare(first->elem, thisElem)) > 0) {
        TList aux = malloc(sizeof(*aux));

        /* Coloco el elem adelante. */
        aux->elem = thisElem;
        aux->tail = first;
        aux->count = 1;
        *ctr = aux->count;
    }
    /* Caso 2: thisElem > first->elem. */ 
    if (cmp < 0) {
        /* Recursivamente con la sublista siguiente (nodo). */
        first->tail = addRec(first->tail, thisElem, ctr);
    /* Caso 3: iguales (c == 0). */
    } else {
        *ctr = ++(first->count);
    }

    return first;
}

unsigned int add(bagADT bag, elemType elem)
{
    unsigned int ctr;
    bag->first = addRec(bag->first, elem, &ctr);

    if (ctr == 1)
        bag->size++;

    return ctr;
}
static unsigned int countRec(TList first, elemType thisElem) 
{
    int cmp;
    /* Caso 1: primera rec o first->elem > thisElem. 
     * Como esta ascend. si first->elem > thisElem no hay mas repetidos. 
     */
    if (first == NULL || (cmp = compare(first->elem, thisElem) > 0)) {
       return 0; 
    }
   
    /* Caso 2: son iguales, o sea, repetido. */
    if (cmp == 0) {
        return first->count;
    }

    return countRec(first->tail, thisElem);
}

unsigned int count(const bagADT bag, elemType elem)
{
    return countRec(bag->first, elem); 
}

unsigned int size(const bagADT bag)
{
    /* Como bag es un struct con TList first, entonces cada elemento repetido se
     * guarda en count de cada nodo, por lo que size tiene cantidad de elemntos
     * sin repetir. */
    return bag->size;
}

elemType mostPopular(bagADT bag)
{
    elemType mPop;
    
    if (bag->size == 0) exit(1);

    /* Inicializo. */
    TList aux = bag->first;
    int ctr= aux->count;
    mPop = aux->elem;
    aux = aux->tail;
    
    /* Recorro y guardo el que tenga mas apariciones. */
    while (aux != NULL) {
        /* Si tuvo mas apariciones entonces cambiarlo al siguiente y actualizar
         * al nuevo mayor contador. */
        if (aux->count > ctr) {
            mPop = aux->elem;
            ctr = aux->count;
        }
        aux = aux->tail;
    }

    return mPop;
}
