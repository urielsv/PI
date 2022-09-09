// Una función que determine si un número es primo.

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "/home/urielsv/PI/getnum.h"

int esPrimo(int num);
int nPrimos(int num);

int main() 
{   
   // Test Función esPrimo
   assert(!esPrimo(0)); // 0 no es primo (no es natural)
   assert(!esPrimo(1)); // 1 no es primo
   assert(esPrimo(2)); // 2 es primo
   assert(esPrimo(3));
   assert(!esPrimo(4));
   assert(esPrimo(5));
   assert(!esPrimo(6)); // Equivalente a assert(esPrimo(6) == 0)
   assert(esPrimo(7)); // Equivalente a assert(esPrimo(7) == 1)
   printf("OK!\n");
   // Ejemplo invocación función primerosNPrimos
    int num = getint("");
    printf("%s\n", esPrimo(num) ? "Es primo" : "No es primo");
    printf("%d\n", nPrimos(num));
    return 0;
}

int esPrimo(int num)
{
    int es = 1;
    if (num == 0 || num == 1) {
        return !es;
    } 
    if (num % 2 == 0 && num != 2) {
        return !es;
    } else if ( num == 2 ) {
        return es;
    } 

    for(int i= 3; i*i <= num && es; i+=2) { // Hay que ver el caso del 1.
        if (num % i == 0) { 
            es = 0; 
        }
    }
    return es;     
}

int nPrimos(int num)
{
    int prim_ctr = 0;
    for(int i = 2; i <= num; i++) {
        if (esPrimo(i)) {
            prim_ctr++;
        }
    }
    return prim_ctr;
}
