/*
 * Escribir un programa (en no más de 10 líneas) que calcule 
 * el valor de la constante matemática e utilizando la 
 * fórmula e = 1 + 1/1! + 1/2! + 1/3! +... e imprima una tabla 
 * que indique cantidad de términos de la serie y el resultado 
 * parcial, con el siguiente formato:
 * N e
 * 1 1
 * 2 2
 * 3 2.5
 * 
 * ¿Qué criterio utilizaría para detener la secuencia? 
 * ( No usar cantidad fija de términos ni preguntarle al usuario 
 * la cantidad de términos. Tampoco tendría sentido comparar 
 * con el verdadero valor de e).
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

#define     EPSILON     0.000001 

int main() 
{
    unsigned int fact = 1;
    double e = 1;
    double aux = 0;
    printf("N\te\n");
    for(int i = 1; e - aux >= EPSILON ; i++) {  
        fact *= i; 
        printf("%d\t%.5f\n", i, e); 
        aux = e;
        e += 1.0 / fact;
    }

    return 0;
}
