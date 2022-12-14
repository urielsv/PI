/*
 * La función floor puede ser utilizada para redondear un número a una 
 * cantidad específica de lugares decimales. 
 * Por ejemplo, floor( x * 100 + .5 ) / 100 redondea x a la posición de los centésimos.
 *
 * a) Escribir una función redondeo que reciba dos parámetros de entrada
 * correspondientes al número a redondear y la cantidad de cifras decimales que 
 * se desean, y que devuelva en su nombre el número redondeado (en no más de 5 líneas).
 *
 * b) Escribir un programa que ofrezca el siguiente menú para redondear un 
 * número x de varias formas e utilice la función anterior para cada una de ellas:
 * ▪ Redondeo al entero más cercano
 * ▪ Redondeo a la décima más cercana.
 * ▪ Redondeo a la centésima más cercana.
 * ▪ Redondeo a la milésima más cercana.
 */

#include <stdio.h>
#include <math.h>
#include "/home/uriel/PI/getnum.h"

double redond(double, unsigned int);

int main() 
{
    double a = getfloat("Numero a redondear: ");
    int b = getint("Cantidad de centesimos: ");
    printf("%f", redond(a, b));
    return 0;
}
double redond(double num, unsigned int cent)
{
    int exp = pow(10, cent); 
    return floor( num * exp + .5) / exp;
}
