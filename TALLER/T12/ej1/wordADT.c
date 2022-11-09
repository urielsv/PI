#include "wordADT.h"

struct wordCDT {
    char * let; 
    unsigned int len;
};

/* 
 * De forma recursiva con listas:
 * typedef struct palabraCDT {
 *      char let;
 *      struct palabraCDT * sig;
 * } palabraCDT;
 *
 */
