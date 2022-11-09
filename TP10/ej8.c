#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "utillist.h"

TList listUnion(TList l1, TList l2);

int main()
{
    return 0;
}

TList listUnion(TList l1, TList l2)
{
    if (l1 == NULL && l2 == NULL) return NULL;

    if (l1 == NULL) return listUnion(l2, l1);

    TList aux = malloc(sizeof(*aux));

    if (l2 == NULL || l1->head < l2->head) {
        aux->head = l1->head;
        aux->tail = listUnion(l1->tail, l2);
    }

    if (l1-> head > l2->head) {
       aux->head = l2->head;
       aux->tail = listUnion(l1, l2->tail);
       return aux;
    } else {
       aux->head = l1->head;
       aux->tail = listUnion(l1->tail, l2->tail);
    }

    return aux; 
}
