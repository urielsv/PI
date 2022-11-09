/*
 * Escribir un programa que convierta enteros de una base a otra. Los números entre 
 * y después de los símbolos '<' y '>' indican la base de entrada y de salida respectivamente. 
 * Dichos números serán decimales entre 2 y 10.
 */

#include <stdio.h>

void readBase(unsigned int * srcBase, unsigned int * trgBase);


int main() 
{

    /* Leo la base de forma <5> 2 */
    /* Luego leo el numero que quiero pasar src to trg */
    return 0;
}

void readBase(unsigned int * srcBase, unsigned int * trgBase)
{
    /* Una base es valida si esta entre 2 o 10. */
    int n1, n2, flag;
    do { 
        printf("Ingrese una base de origen y final como <o> f: ");
        flag = scanf("<%d>%d", &n1, &n2);
        fflush(stdin);
    } while ((flag < 2) || (flag > 10));
    *srcBase = n1;
    *trgBase = n2;
}

/* Terminar.
