/*
 * Escribir un programa que lea dos enteros y a continuación imprima 
 * el promedio, la suma, el menor y el mayor de ellos (o indicar que son iguales).
 * Usar el operador condicional.
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

int main() {

    int num1, num2;
    num1 = getint("");
    num2 = getint("");

    printf("Prom: %.1f, Suma: %d, Menor: %d, Mayor: %d, %s\n", (num1 + num2) / 2.0, num1 + num2, num1 < num2 ? num1 : num2, num1 > num2 ? num1 : num2, (num1 == num2) ? "Son iguales" : "Son distintos");

    return 0;
}
