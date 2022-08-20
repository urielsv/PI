/*
 * Escribir una funcion real para calcular aprox. el valor de e^x por medio de
 * la serie: 1+x + x^2 / 2! + x^3 / 3! + ...
 * 
 * Dicha funcion recibe como parametros de entrada el valor de x. 
 * (En no mas de 10 lineas)
 *
 * Hacer un programa que invoque a la funcion y escriba el resultado de la misma
 * el valor de la funcion exp(x) de C.
 */

#include <stdio.h>
#include <math.h>

double exp_l(int exp) {
    
    double aux = 1;
    int fact = 1;
   
    // Hasta donde puede ir i (i mejora presicion por S. Taylor?)?
    for (int i = 1; i <= 10 ; i++) { // Habria que corregir para que sea por
                                     // presicion y no por x terminos.
        fact *= i;
        aux += pow(exp, i)/fact; 
    } 
    return aux;
}

int main() 
{
    printf("%.3f", exp_l(-2));
    return 0;
}
