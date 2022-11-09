#include <stdlib.h>
#include <stdlib.h>
#include "complex.h"

struct complexCDT {
    float real;
    float imag;
};

complexADT newComp(float thisReal, float thisImag)
{
    complexADT comp = malloc(sizeof(*comp));
    if (comp == NULL) return NULL;
    comp->real = thisReal;
    comp->imag = thisImag;
    return comp;
}

float getRealComp(complexADT num)
{
    return num->real;
}

float getImagComp(complexADT num)
{
    return num->imag;
}

complexADT sumComp(complexADT c1, complexADT c2)
{
    complexADT sum = newComp(c1->real + c2->real, c1->imag + c2->imag);
    return sum;
}

void freeComp(complexADT comp)
{
    free(comp);
}

