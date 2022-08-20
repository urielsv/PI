/*
 * Escribir un programa que lea una variable tipo float
 * representando una velocidad en m/s, e imprima en la 
 * salida estándar el equivalente en km/h. 
 * Utilizar una única variable.
 */
#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

#define MS_TO_KMH 3.6

int main() {

    float vel;
    vel = getfloat("Ingresar velocidad (m/s): ");

    printf("%.2f km/h\n", vel * MS_TO_KMH);

    return 0;
}

