/*
 * Escribir una función que tome como argumentos los coeficientes de una
 * ecuación cuadrática y calcule el resultado de la ecuación.
 * Debe devolver un valor entero.
 */

#include <stdio.h>
#include <math.h>

// Si debe ser int entonces hasta ahora (con lo que sabemos) solo podria
// devoler una unica solucion.
int solCuadratica(double a, double b, double c);

int main()
{
    solCuadratica(1,2,0);
    return 0;
}

int solCuadratica(double a, double b, double c)
{
    double sol1 = (-b + sqrt(b*b - 4*a*c))/2*a;
    double sol2 = (-b - sqrt(b*b - 4*a*c))/2*a;
    int soluciones = (sol1 != sol2) + 1; 

    if (b*b >= 4*a*c) {
        printf("%.2f y %.2f", sol1, sol2); 
    } else { 
        printf("No tiene raices reales");
        soluciones = 0;
    }
    return soluciones;
}


