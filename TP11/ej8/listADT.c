#include "listADT.h"
#include <stdlib.h>

typedef struct node {
    elemType elem;
    struct node * tail;
} node;

struct listCDT {
    size_t size;    // cantidad de nodos
    node * first;
    compare cmp;
    node * next;    // para poder iterar
};

listADT newList(compare cmp) {
    listADT list = calloc(1, sizeof(struct listCDT));
    list->cmp = cmp;
    return list;
}

void freeList(listADT) {

}

size_t size(const listADT list) {
    return list->size;
}

static int belongsRec(node * first, elemType elem, compare cmp) {
    int c;
    if (first == NULL || ( c = cmp(first->elem,elem)) > 0 )  {
        return 0;
    }
    // son iguales ?
    if (c==0) {
        return 1;
    }
    return belongsRec(first->tail, elem, cmp);
}

int belongs(const listADT list, elemType elem) {
    return belongsRec(list->first, elem, list->cmp);
}

/**
 *
 * @param first puntero al primer nodo de la lista actual
 * @param elem el elemento a insertar
 * @param cmp función de comparación,
 * @param flag guardar 1 si se insertó
 * @return
 */
static node * addRec(node * list, elemType elem, compare cmp, int * flag) {
    int c;
    if ( list == NULL || ( (c=cmp(list->elem, elem)) > 0) ) {
        node * aux = malloc(sizeof(node));
        aux->elem = elem;
        aux->tail = list;
        *flag= 1;
        return aux;
    }
    if ( c < 0 ) {
        list->tail = addRec(list->tail, elem, cmp, flag);
    }
    return list;
}

int add(listADT list, elemType elem) {
    int flag=0;
    list->first = addRec(list->first, elem, list->cmp, &flag);
    list->size += flag;
    return flag;
}

void toBegin(listADT list) {
    list->next = list->first;
}

int hasNext(const listADT list) {
    return list->next != NULL;
}
