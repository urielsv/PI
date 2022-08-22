/*
 * Difficulty: *__
 *
 * Reescribir el ejercicio 10 de la práctica 5 de forma tal que quede 
 * separado correctamente el front-end del back-end.
 *
 * Para la opción de simplificar una fracción, la obtención del numerador 
 * y denominador pertenece al front-end. Luego se invoca a una función de 
 * back-end que recibe esos parámetros y los modifica. 
 * ¿Cómo se puede hacer para que la función de back-end reciba ambos 
 * y los pueda modificar?
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "/home/uriel/PI/getnum.h"

void menu();
void minFrac(int *, int *);
void sumFrac(int *, int *, int *, int *, int *, int *);

int main()
{
    int nu1, nu2, de1, de2, opt; 
    int sumNum, sumDen;
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
            minFrac(&nu1, &de1);
            printf("%d/%d\n", nu1, de1);
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
            sumFrac(&nu1, &de1, &nu2, &de2, &sumNum, &sumDen);
            printf("%d/%d\n", sumNum, sumDen); 
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
void minFrac(int * num, int * den)
{
    const int mayor = MAYOR(*num,*den); 
    for (int i= 2; i < mayor; i++) {
        if ((abs(*num) % i == 0) && (abs(*den) % i == 0)) {
                *num /= i;
                *den /= i;
        }
    }
}
#undef      MAYOR

void sumFrac(int * num1, int * den1, int * num2, int * den2, int * sumNum, int * sumDen)
{
    *sumNum = *num1 * *den2 + *num2 * *den1;
    *sumDen = *den1 * *den2;
    minFrac(sumNum, sumDen);
}
