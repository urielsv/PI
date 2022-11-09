#include <stdio.h>
#include <stdlib.h>
#include "moveToFrontADT.h"

typedef struct node {
    elemType elem; 
    struct node * next;
} TNode;

typedef struct moveToFrontCDT {
    TNode * first;
    TNode * iter;
    size_t size;
    int (*cmp)(elemType e1, elemType e2);
} moveToFrontCDT;

moveToFrontADT newMoveToFront(int (*compare)(elemType e1, elemType e2))
{
    moveToFrontADT new = calloc(1, sizeof(moveToFrontCDT));
    new->cmp = compare;
    return new;
}

unsigned int size(moveToFrontADT moveToFront)
{
    return moveToFront->size;
}

void toBegin(moveToFrontADT moveToFront)
{
    moveToFront->iter = moveToFront->first;
}

int hasNext(moveToFrontADT moveToFront)
{
    return moveToFront->iter != NULL;
}

elemType next(moveToFrontADT moveToFront)
{
    if (moveToFront->iter == NULL) exit(1);

    elemType ans = moveToFront->iter->elem;
    moveToFront->iter = moveToFront->iter->next;
    return ans;
}

static void freeRec(TNode * first)
{
    if (first == NULL) return;
    freeRec(first->next);
    free(first);
}

void freeMoveToFront(moveToFrontADT moveToFront)
{
    freeRec(moveToFront->first);
    free(moveToFront);
}

static TNode * addRec(TNode * first, elemType elem, int * flag) 
{
    int cmp;
    if ( first == NULL ) {
            TNode * aux = malloc(sizeof(TNode));
            aux->elem = elem;
            aux->next = NULL;
            *flag = 1;
            return aux; 
    }

    if (cmp = compare(first->elem, elem) == 0)
        return first;

    first->next = addRec(first->next, elem, flag);
    return first;

}

unsigned int add(moveToFrontADT moveToFront, elemType elem)
{
    int flag = 0;
    moveToFront->first = addRec(moveToFront->first, elem, &flag);
    moveToFront->size += flag;
    return flag;
}

static TNode * getRec(TNode * first, elemType thisElem, TNode ** flag)
{
    int cmp;
    if (first == NULL) {
        *flag = 0;
        return NULL;
    }

    if (compare(first->elem, thisElem) == 0) {
        *flag = first;
        return first->next;
    }

    first->next = getRec(first->next, thisElem, flag);
    return first;
}

elemType * get(moveToFrontADT moveToFront, elemType elem)
{
    TNode * flag;
    /* Busco y desconecto el nodo si se encontro. */
    moveToFront->first = getRec(moveToFront->first, elem, &flag);

    /* Si no estaba retorno NULL. */
    if (flag == NULL) return NULL;

    /* Coloco en sublista nueva la vieja lista sin el nodo. */
    flag->next = moveToFront->first;
    /* Coloco el nodo al principio de todo. */
    moveToFront->first = flag;
    /* Guardo la respuesta. */
    elemType * ans = malloc(sizeof(elemType));
    *ans = flag->elem;
    return ans;
}
