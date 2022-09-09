/*
 * Escribir un programa que simule la tirada de 5 dados.
 * Determinar si se formó generala.
 */
#include <stdio.h>

#include "random.h"

#define CANT_DADOS   6
int main()
{
    randomize();
    int dado[CANT_DADOS];

    int esGenerala = 1;
    for (int i=0; i < CANT_DADOS; i++) {
        dado[i] = randInt(2,6);
        printf("%d\n", dado[i]);

        if (dado[0] != dado[i])
            esGenerala = 0;
    }
    printf("%d", esGenerala);
    return 0;
}
