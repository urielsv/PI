/*
 * Escribir una función que reciba tres parámetros de entrada de tipo entero 
 * y que devuelva en su nombre el mayor de ellos. (En 2 líneas)
 */

#include <stdio.h>

int mayorDeTres(int a, int b, int c) {
    return ((a > b && a > c) ? a : (b > c ? b : c));
}

int main() {
    
    printf("%d", mayorDeTres(1,2,3));
    return 0;
}
