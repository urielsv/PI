#include <stdio.h>
#include <stdlib.h>
#include "sets.h"
#include "listADT.h"

struct node {
    elemType elem;
    struct node * next;
};

typedef struct node * TList;

struct setsCDT {
    TList list;
};

setsADT newSet()
{
    setsADT mySet = malloc(sizeof(*mySet));
    
    if (mySet == NULL) return NULL;

    mySet->list = newList();
    return mySet;
}
 
void addElem(setsADT set, elemType elem)
{
    add(set->list, elem);
}

void remElem(setsADT set, elemType elem)
{
    remove(list->list, elem);
}

setsADT union(setsADT s1, setsADT s2)
{
    setADT mySet;
    TList l1, l2;

    mySet = newSet();
    if (mySet == NULL) return mySet;
    
    l1 = s1->list;
    l2 = s2->list;

    /* recorro si son iguales y los guardo. */
    toBegin(l1);
    if (s1 == s2) {
        while (hasNext(l1))
            addElem(mySet, next(l1)); // Recuerdo que next retorna el actual y
                                    // apunta al siguiente.
    }

    if (hasNext(l1) || hasNext(l2)) {
        elemType e1, e2;
        int h1, h2;

        if (h1 = hasNext(l1))
            e1 = next(l1);
        if (h2 = hasNext(l2))
            e2 = next(l2);

        while (h1 || h2) {
            /* Caso 1: l2 no tiene siguiente o l1 tiene y e2 > e1. */
            if (!h2 || (h1 && compare(e1,e2) < 0)) {
                addElem(mySet, e1);
                if (h1 = hasNext(l1))
                    e1 = next(l1);
            /* Caso 2: l1 no tiene siguiente o l2 tieney  e2 < e1. */
            } else if (!h1 || (h2 && compare(e1, e2) > 0)) {
                addElem(mySet, e2);
                if (h2 = hasNext(l2))
                    e2 = next(l2);
            /* Caso 3: si son iguales. */
            } else {
                addElem(mySet, e1);
                if (h1 = hasNext(l1))
                    e1 = next(l1);
                if (h2 = hasNext(l2))
                    e2 = next(l2);
            }
        }

    }

}
setsADT inter(setsADT s1, setsADT s2)
{
    setsADT mySet;
    TList l1, l2;

    mySet = newSet();
    if (mySet == NULL) return mySet;
    
    l1 = s1->list;
    l2 = s2->list;

    toBegin(l1);
    if (s1 == s2) {
        while (hasNext(l1))
            addElem(mySet, next(l1));
        return mySet;
    }

    int h1 = hasNext(l1);
    int h2 = hasNext(l2);

    /* Primero checkeo que hayan elementos y guardo los primeros. */
    if ( h1 && h2 ) {
        e1 = next(l1); 
        e2 = next(l2); 
    }

    while ( h1 && h2 ) {
        /* Caso 1: e1 > e2 , continuo e1 (si hay next) */
        if (compare(e1, e2) < 0) {
           if (h1 = hasNext(l1))
               e1 = next(l1);
        /* Caso 2: e2 > e1 , continuo e2 (si hay next) */
        if (compare(e2, e1) < 0) {
           if (h2 = hasNext(l2))
               e2 = next(l2);
        /* Caso 3: son iguales, guardo. */
        } else {
           addElem(mySet, e1);
           if (h1 = hasNext(l1))
               e1 = next(l1);
           if (h2 = hasNext(l2))
               e2 = next(l2);
        }
    }
    return mySet;

}

setsADT substr(setsADT s1, setsADT s2)
{
    setsADT mySet;
    TList l1, l2;

    mySet = newSet();
    if (mySet == NULL || s1 == s2) return mySet;
    
    l1 = s1->list;
    l2 = s2->list;

    toBegin(l1);
    toBegin(l2);

    if (h1 = hasNext(l1))
        e1 = next(l1);
    if (h2 = hasNext(l2))
        e2 = next(l2);

    while (h1) {
        /* Caso 1: l2 no tiene next o e1 > e2. */
        if (!h2 || compare(e1, e2) < 0) {
            /* Comment temporal.
             * Recuerdo: esta ordenada ascend. */
            addElem(mySet, e1);
            if (h1 = hasNext(l1))
                e1 = next(l1);
        /* Caso 2: e1 > e2. */
        } else if (compare(e1, e2) > 0) {
            if (h2 = hasNext(l2))
                    e2 = next(l2);
        /* Caso 3: e1 = e2. */
        } else {
            if (h1 = hasNext(l1))
                e1 = next(l1);
            if (h2 = hasNext(l2))
                e2 = next(l2);
        }
    }
    return mySet;

}


