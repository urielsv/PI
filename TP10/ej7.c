#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utillist.h"

TList listIntersec(TList l1, TList l2);

int main() 
{
    return 0;
}

TList listIntersec(TList l1, TList l2)
{
    if (l1 == NULL || l2 == NULL) return NULL;

    if (l1->head == l2->head) {
        TList aux = malloc(sizeof(*aux));
        aux->head = l1->head;
        aux->tail = listIntersec(l1->tail, l2->tail);
        return aux;
    }

    if (l1->head > l2->head) 
        return listIntersec(l1, l2->tail);

    return listIntersec(l1->tail, l2);
}
