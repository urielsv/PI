/*
 * Escribir una macro MAXIMO2 que recibiendo tres parámetros, asigne al 
 * tercer parámetro el mayor de los dos primeros. Utilizarla en un programa 
 * para verificar su correcto funcionamiento. (En no más de 5 líneas)
 */

#include <stdio.h>

#define     MAXIMO2(x,y,max)        (max = (x>y) ? x : y)   

int main() {
    double a = 5.0;
    int b = 2;
    double maximo;
    MAXIMO2(a,b,maximo);
    printf("%g", maximo);
    return 0;
}
