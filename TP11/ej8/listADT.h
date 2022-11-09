#ifndef LISTADT_LISTADT_H
#define LISTADT_LISTADT_H

#include <stdio.h>
typedef struct listCDT * listADT;

// Tipo de elemento de la lista
typedef struct {
    double key;
    char * text;
} elemType;

/**
 * Función de comparación. Debe retornar < 0 si e1 tiene que estar antes en la lista
 * Debe retornar > 0 si e1 tiene que estar después en la lista
 * Debe retornar cero si e1 y e2 representan el mismo elemento
 */
typedef int (*compare) (elemType e1, elemType e2);

listADT newList(compare cmp);

void freeList(listADT list);

size_t size(const listADT list);

/**
 *
 * @param list
 * @param elem
 * @return 1 si elem pertenece a la lista
 */
int belongs(const listADT list, elemType elem);

/**
 *
 * @param list
 * @param elem
 * @return la posición que ocupa elem en la lista,o -1 si no está en la lista
 */
//int indexOf(const listADT list, elemType elem);

/**
 * Si idx es una posición afuera de la lista, aborta la ejecución
 * @param list
 * @param idx
 * @return el elemento que está en la posición idx, siendo 0 la primer posición
 */
//elemType get(const listADT list, unsigned int idx);

// Funciones para agregar, eliminar, recorrer la lista

/**
 *
 * @param list
 * @param elem
 * @return 1 si lo agregó, cero si no lo agregó
 */
int add(listADT list, elemType elem);

void toBegin(listADT list);

int hasNext(const listADT list);

/**
 * si no hay siguiente elemento, aborta
 * @param list
 * @return
 */
elemType next(listADT list);

#endif //LISTADT_LISTADT_H

