/*
 * Escribir un programa que lea dos enteros, e imprima 
 * si el segundo es múltiplo del primero. 
 * Usar el operador condicional.
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

int main() {
    
    int num1, num2;
    num1 = getint("Primer numero: ");
    num2 = getint("Segundo numero: ");

    printf("%s\n", num2 % num1 == 0 ? "Es multiplo" : "No multiplo uwun\'t");
    
    return 0;
}
