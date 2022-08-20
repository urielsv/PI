/*
 * Escribir un programa que lea una variable entera que 
 * representa un intervalo de tiempo expresado en segundos. 
 * Realizar la conversión para imprimir en la salida estándar 
 * el equivalente en horas, minutos y segundos. 
 * No utilizar variables auxiliares.
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

#define HOUR    3600
#define MIN     60
int main() {
    int t_intr;
    t_intr = getint("Ingresar tiempo (en segs): ");

    printf("H: %d, M: %d, S:%d\n", t_intr / HOUR, (t_intr % HOUR) / MIN, (t_intr % HOUR) % MIN);

    return 0;
}
