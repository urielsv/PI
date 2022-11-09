#ifndef __BAG_ADT_H
#define __BAG_ADT_H

typedef struct bagCDT * bagADT;
typedef int elemType;

static int compare (elemType e1, elemType e2) {
    /* Completar */
}

void freeBag(bagADT bag);
bagADT newBag();
unsigned int add(bagADT bag, elemType elem);
unsigned int count(const bagADT bag, elemType elem);
unsigned int size(const bagADT bag);
elemType mostPopular(bagADT bag);

#endif
