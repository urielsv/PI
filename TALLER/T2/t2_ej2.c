/*
 * Escribir un programa que permita al usuario ingresar 
 * los coeficientes de una ecuación cuadrática y luego imprima la solución.
 */

#include <stdio.h>
#include <math.h>
#include "/home/urielsv/PI/getnum.h"

int main()
{
    double a,b,c;
    
    do {
    a = getdouble("Coef. cuadratico: ");
    } while (a <= 0);
    b = getdouble("Coef. lineal: ");
    c = getdouble("Coef. indep: ");
    
    double sol1 = (-b + sqrt(b*b - 4*a*c))/2*a;
    double sol2 = (-b - sqrt(b*b - 4*a*c))/2*a;
    
    if (b*b >= 4*a*c) {
        printf("%.2f y %.2f", sol1, sol2); 
    } else {
        printf("No tiene raices reales");
    }

    return 0;
}
