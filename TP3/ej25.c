/*
 * Ejercicio 25 - Ejercicio de Parcial - TP3
 * Autor: urielsv
 * Fecha: 12/08/22 (DD/MM/YY)
 *
 * Escriba un programa que lea de entrada estándar un número 
 * entero positivo y calcule la cantidad de bits en ‘1’ que contiene. 
 *
 * Por ejemplo:
 * Si el número es 1, imprime 1
 * Si el número es 64, imprime 1
 * Si el número es 229, imprime 5
 */
#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

#define     BIN_BASE        2

int main() {
   
    int num;
    int bit_counter = 0;
    
    do {
        num = getint("Numero entero positivo: ");
    } while (num < 0);

    while (num != 0) {
        if (num % BIN_BASE == 1) 
            bit_counter++;
        num >>= 1;
    } printf("Cantidad de bits en 1: %d\n", bit_counter);

    return 0;
}
