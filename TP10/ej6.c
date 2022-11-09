#include <stdio.h>
#include <stdlib.h>
#include "utillist.h"

TList deleteDupl(TList l);

int main()
{

    puts("OK!");
    return 0;
}

TList deleteDupl(TList l)
{
    if (l == NULL || l->tail == NULL) return l;

    TList aux = deleteDupl(l->tail);

    /* Si son iguales libera y devuelve la lista sin ese elem. */
    if (l->head == aux->head) {
        free(l);
        return aux;
    }
    
    /* Apunta al ultimo elemento (recur). */
    l->tail = aux;
    return l;
}
