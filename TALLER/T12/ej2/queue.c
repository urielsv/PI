#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node {
    elemType value;
    struct node * next;
} TNode;
typedef struct node * TList;

struct queueCDT {
   TNode * first;
   TNode * last;
};

queueADT newQueue()
{
    /*
     * Inicializo la Queue con malloc para checkear si llega a estar vacia.
     * Obs: si lo hiciera con malloc tendria basura por lo que no podria igualar
     * con NULL.
     */
    return calloc(1, sizeof(struct queueCDT));
}

void addQueue(queueADT q, elemType elem)
{
    /* Agrego la lista con ceros y guardo el elemento. */
    TList aux = calloc(1, sizeof(*aux));
    aux->value = elem;

    /* 
     * Si la lista esta vacia entonces los punteros 
     * apuntan al mismo elemento.
     **/
    if (q == NULL) {
        q->first = q->last = aux;
        return;
    }
    
    /* Marco el puntero last al nuevo elemento. */
    q->last = aux;
}

void dequeue(queueADT q, elemType * out)
{
    if (q == NULL)
        return; 
    /* Guardo el elemento que estoy por sacar de la cla en out. */
    *out = q->first->value;

    /* Aux es sublista sin el primer elemento (apunta al siguiente) */
    TList aux = q->first->next;
    /* Libero la lista inicial y luego vuelvo la lista en la sublista aux. */
    free(q->first); 
    q->first = aux;
}

int isEmpty(queueADT q)
{
    return q->first == NULL;
}

void freeList(TList first) 
{
    if (first == NULL) return;

    freeList(first->next);
    free(first);
}

void freeQueue(queueADT q)
{
    freeList(q->first);
    free(q); 
}
