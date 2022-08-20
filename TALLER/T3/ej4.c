// Una función que determine si un número es primo.

#include <stdio.h>
#include <math.h>
#include "/home/urielsv/PI/getnum.h"

int esPrimo(int num);
int nPrimos(int num);

int main() 
{
    int num = getint("");
    printf("%s\n", esPrimo(num) ? "Es primo" : "No es primo");
    printf("%d\n", nPrimos(num));
    return 0;
}

int esPrimo(int num)
{
    int es = 1;
    for(int i= 2; i*i <= num && es; i++) { // Hay que ver el caso del 1.
        if (num % i == 0 || num == 1) { 
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
