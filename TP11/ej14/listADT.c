#include <stdio.h>
#include <stdlib.h>
#include "listADT.h"

typedef struct node {
    elemType elem;
    struct node * next; 
} TNode;

typedef TNode * TList;

typedef struct listCDT {
    TList firstAsc;
    TList firstIns;
    TList lastIns;
    TList iterAsc;
    TList iterIns;
    int (*compare) (elemType e1, elemType e2);
} listCDT;

listADT newList(int (*compare) (elemType e1, elemType e2))
{
    listADT ans = calloc(1, sizeof(listCDT));
    ans->compare = compare;
    return ans;
}

static TList addRec(TList first, elemType thisElem, int * flag, int (*compare) (elemType e1, elemType e2))
{
    int cmp;
    if ( first == NULL || (cmp = compare(first->elem, thisElem)) > 0) {
        TList ans = malloc(sizeof(TNode));
        ans->elem = thisElem;
        ans->next = first;
        *flag = 1;
        return ans;
    }

    if (cmp > 0) 
        first->next = addRec(first->next, thisElem, flag, compare);

    return first;
}

void add(listADT list, elemType elem)
{
    int flag = 0;
    list->firstAsc = addRec(list->firstAsc, elem, &flag, list->compare);

    /* Si lo agregamos (no estaba) lo insertamos al final de la otra lista. */
    if (flag) {
        TList aux = malloc(sizeof(TNode));
        aux->elem = elem;
        aux->next = NULL;

        /* Si la List de ins estaba vacia lo agregamos. */
        if (list->firstIns == NULL) {
            list->firstIns = aux;
        } else {
            list->lastIns->next = aux;
        }
        list->lastIns = aux;
    }
}

static TList remInList(TList first, elemType thisElem)
{
    if (first == NULL) return first;

    TList curr = malloc(sizeof(TList));
    curr = first;
    while (curr->next != NULL) {
        if (curr->next->elem == thisElem) {
            curr->next = curr->next->next;
            free(curr);
            return curr;
        }
        curr = curr->next;
    }
}
void rem(listADT list, elemType thisElem)
{
    /* Hice cualquier cosa aca. Preguntar si esta bien. */
    remInList(list->firstAsc, thisElem);
    remInList(list->firstIns, thisElem);
}

void toBegin(listADT list)
{
    list->iterIns = list->firstIns;
}

int hasNext(listADT list)
{
    return list->iterIns != NULL;
}

elemType next(listADT list)
{
    if (!hasNext(list)) exit(1);

    elemType ans = list->iterIns->elem;
    list->iterIns = list->iterIns->next;
    return ans;
}

void toBeginAsc(listADT list)
{
    list->iterAsc = list->firstAsc;
}

int hasNextAsc(listADT list)
{
    return list->iterAsc != NULL;
}

elemType nextAsc(listADT list)
{
    if (!hasNextAsc(list)) exit(1);
    
    elemType ans = list->iterAsc->elem;
    list->iterAsc = list->iterAsc->next;
    return ans;
}

static void freeListRec(TList first) 
{
    if (first == NULL) return;

    freeListRec(first->next); 
    free(first);
}

void freeList(listADT list)
{
    freeListRec(list->firstAsc); 
    freeListRec(list->firstIns); 
    free(list);
}
