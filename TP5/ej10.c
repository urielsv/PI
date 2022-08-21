/*
 * Escribir un programa que ofrezca un menú con las siguientes opciones:
 * Simplificar una fracción
 * Sumar dos fracciones
 * Terminar la ejecución
 *
 * Si se elige la primera opción se le solicitará numerador y denominador 
 * de la fracción y se imprimirá la fracción simplificada (algunos de ellos 
 * podrían ser negativos). Si se opta por la segunda, se le solicitará dos 
 * fracciones y se imprimirá la suma de las mismas, también simplificada. 
 * Obviamente con la tercera opción finaliza la ejecución del mismo. 
 * Escribir una función para cada item del menú. 
 * (No más de 20 líneas para main y no más de 10 líneas para las funciones del menú).
 * Pista: Escribir y usar la función DivisorComunMaximo.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "/home/uriel/PI/getnum.h"

void menu();
void printFrac(int, int);
void printSumaFrac(int, int, int, int);

int main()
{
    int nu1, nu2, de1, de2, opt; 
    menu();
    
    opt = getint("Opcion (1-3): ");
    switch(opt) { 
        case 1:
            nu1 = getint("Numerador:");
            de1 = getint("Denominador:");
                if (de1 == 0) {
                    printf("No se puede divir por 0.");
                    return 1;
                }
            printFrac(nu1, de1);
            break;
        case 2:
            nu1 = getint("Numerador 1:");
            de1 = getint("Denominador 1:");
            nu2 = getint("Numerador 2:");
            de2 = getint("Denominador 2:");
                if (de1 == 0 || de2 == 0) {
                    printf("No se puede divir por 0.");
                    return 1;
                }
            printSumaFrac(nu1, de1, nu2, de2);
            break;
        case 3:
            return 0;
            break;
        default:
            puts("Opcion invalida.");
            break;
    }
    return 0;
}

void menu()
{
    printf("\n1. Simplificar una fraccion\n"
            "2. Sumar dos fracciones\n"
            "3. Terminar la ejecucion\n");
}

#define     MAYOR(x,y)      ((x) > (y) ? (x) : (y))
void printFrac(int num, int den)
{
    const int mayor = MAYOR(num,den); 
    for (int i= 2; i < mayor; i++) {
        if ((abs(num) % i == 0) && (abs(den) % i == 0)) {
                num /= i;
                den /= i;
        }
    }
    printf("%d/%d\n", num, den);
}
#undef      MAYOR

void printSumaFrac(int num1, int den1, int num2, int den2)
{
    int sumNum = num1 * den2 + num2 * den1;
    int sumDen = den1 * den2;
    
    printFrac(sumNum, sumDen);
}
