#include <stdio.h>
#include <stdlib.h>
#include "rankingADT.h"

struct rankingCDT {
    elemType * elems;
    size_t size;
};

rankingADT newRanking(elemType elems[], size_t dim, int (*compare)(elemType source, elemType target))
{
    rankingADT ans = malloc(sizeof(struct rankingCDT));
    ans->size = dim;
    if (dim > 0) {
        ans->elems = malloc(sizeof(struct rankingCDT) * dim);

        for (int i = 0; i < dim; i++)
            ans->elems[i] = elems[i]; 

    } else {
        ans->elems = NULL;
    }
    return ans; 
}

static int where(rankingADT ranking, elemType elem)
{
    for (int i = 0; i < ranking->size; i++) {
        if (compare(ranking->elems[i], elem) == 0)
            return i;
    }
    return -1;
}

static void swap(rankingADT ranking, size_t n, size_t m)
{
    elemType aux = ranking->elems[n]; 
    ranking->elems[n] = ranking->elems[m];
    ranking->elems[m] = aux;
}

void addRanking(rankingADT ranking, elemType elem)
{
    /* Si no esta, lo coloco al final. */
    size_t idx;
    if ((idx = where(ranking, elem)) < 0) {
        realloc(ranking->elems, sizeof(struct rankingCDT) * (ranking->size + 1));
        ranking->elems[ranking->size++] = elem;
        return;
    }

    /* Si esta entonces aplico el swap. */
    swap(ranking, idx, idx-1);
}

size_t size(const rankingADT ranking)
{
    return ranking->size;
}

int getByRanking(rankingADT ranking, size_t n, elemType * elem)
{
    if (n <= 0 || n > ranking->size) return 0;
        
    *elem = ranking->elems[n-1];

    /* Para no swapear con basura. */
    if (n > 1) {
        swap(ranking, n-1, n-2);
    }

    return 1;
}

elemType * getTopRanking(const rankingADT ranking, size_t * top)
{
   size_t rSize = ranking->size;

   if (rSize == 0) {
        *top = 0;
        return NULL;
   }

   if (*top > rSize) 
        *top = rSize;

   elemType * ans = malloc(sizeof(elemType) * (*top));
   
   for (int i = 0; i < *top; i++)
        ans[i] = ranking->elems[i];

   return ans;
}

int contains(rankingADT ranking, elemType elem)
{
    size_t idx = where(ranking, elem);
    if (idx > 0) swap(ranking, idx, idx-1);
    return idx >= 0;
}

void downByRanking(rankingADT ranking, size_t n)
{
    swap(ranking, n-1, n);
}

void freeRanking(rankingADT r)
{
   free(r->elems);
   free(r);
}
