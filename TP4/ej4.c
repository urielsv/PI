/*
 * Resolver el problema 4-14 del K&R. Utilizar la macro definida en un 
 * programa que realice intercambio de variables. (En no más de 5 líneas)
 *
 * Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block
 * structure will help).
 */

#include <stdio.h>

// MI SOLUCION:
#define SWAP(t,x,y)     { t aux = x; \
                            x = y; \
                            y = aux; }

// SUPUESTA SOLUCION POR K&R:
#define swap(t, x, y) 
  do { 
   t safe ## x ## y; 
   safe ## x ## y = x; 
   x = y; 
   y = safe ## x ## y; 
  } while (0)

int main() 
{
    int a = 5;
    int b = 7; 
    printf("a: %d y b: %d\n", a, b); 

    SWAP(int, a, b);
    printf("a: %d y b: %d\n", a, b);
   
    return 0;
}
