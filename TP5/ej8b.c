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
void menu();

int main() 
{
    double a = 467.93819;
    menu(); 
    
    unsigned int opt = getint("Opcion (1-4): ");
    switch (opt) {
        case 1: 
            a = redond(a, 0); 
            break;
        case 2:
            a = redond(a, 1);
            break;
        case 3:
            a = redond(a, 2);
            break;
        case 4:
            a = redond(a, 3);
            break;
        default:
            printf("Opcion invalida.");
    }
    printf("%f", a);
    return 0;
}

void menu() 
{ 
    printf("\n1. Redondeo al entero mas cercano\n"
            "2. Redondeo a la decima mas cercana\n"
            "3. Redondeo a la centesima mas cercana\n"
            "4. Redondeo a la milesima mas cercana.\n");
   }

double redond(double num, unsigned int cent)
{
    int pot = 1;
    for (int i=0; i != cent; i++) 
        pot *= 10;

    num = floor( num * pot + .5) / pot;
    return num;
}
