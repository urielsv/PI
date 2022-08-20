/*
 * Ejercicio 17 - Ejercicio de Parcial - TP4
 * Autor: urielsv
 *
 * Escribir la macro ELAPSED que al recibir dos medidas de tiempo 
 * en horas y minutos retorne la cantidad de minutos transcurridos. 
 * No usar funciones de la biblioteca estándar.
 * Ejemplos de invocación:
 *
 * int minutos, h1, h2, m1, m2;
 * h1 = 2; m1 = 10; h2 = 3; m2 = 15;
 * minutos = ELAPSED(h1, m1, h2, m2);           minutos = 65
 * minutos = ELAPSED(3, 15, 2, 10);             minutos = 65 
 * minutos = ELAPSED(h1, m1, h1 + 1, m1);       minutos = 60 
 */

#include <stdio.h>

#define     ELAPSED(h1,m1,h2,m2)       (((h1) < (h2)) ? ((h2 - h1)*60 + (m2 - m1)) :\
                                          (h1-h2)*60 + (m1 - m2))
int main() {
    
    int minutos, h1, h2, m1, m2;
    h1 = 9; m1 = 55; h2 = 10; m2 = 5;
    minutos = ELAPSED(h1,m1,h2,m2);
    printf("%d\n", minutos);
    minutos = ELAPSED(3,15,2,10);
    printf("%d\n", minutos);
    minutos = ELAPSED(h1,m1,h1+1,m1); 
    printf("%d\n", minutos);
    return 0;
}
