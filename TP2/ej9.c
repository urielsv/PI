/*
 * Leer un número entero positivo y escribir 
 * en la salida estándar el valor de dicho número 
 * dividido 2, usando decalaje.
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

int main() {

    unsigned int num;
    num = getint("Escribir un numero: ");

    printf("%d\n", num>>1);
    return 0;
}
