#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "utillist.h"

typedef struct nodeBrief * TListBrief;

typedef struct nodeBrief {
    int head;
    size_t count;
    struct nodeBrief * tail;
} TNodeBrief;

TListBrief comprimeList(TList l);

void freeListBrief(TListBrief lb) 
{
   if ( lb == NULL)
     return;
   freeListBrief(lb->tail);
   free(lb);
}

int main()
{
    int v[] = {1,1,2,3,3,3,3,3,10,100,100,998};
    TList list = fromArray(v, sizeof(v)/sizeof(v[0]));
    TListBrief bf = comprimeList(list);

    TListBrief aux = bf;
    assert(aux->head ==1 && aux->count == 2);

    aux = aux->tail;
    assert(aux->head ==2 && aux->count == 1);

    aux = aux->tail;
    assert(aux->head ==3 && aux->count == 5);

    aux = aux->tail;
    assert(aux->head ==10 && aux->count == 1);

    aux = aux->tail;
    assert(aux->head ==100 && aux->count == 2);

    aux = aux->tail;
    assert(aux->head ==998 && aux->count == 1);

    aux = aux->tail;
    assert(aux == NULL);

    freeList(list);
    freeListBrief(bf);
    
    puts("OK!");
    return 0;
}

TListBrief comprimeList(TList l)
{
    if (l == NULL) return NULL;

    TListBrief newList = comprimeList(l->tail);

    if (newList == NULL || l->head < newList->head) {
        TListBrief aux = malloc(sizeof(*aux));
        aux->head = l->head;
        aux->count = 1;
        aux->tail = newList;
        return aux;
    }
    newList->count++;
    return newList;

}
