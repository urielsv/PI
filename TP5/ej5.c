/*
 * Escribir una función potencia, que reciba en dos parámetros de entrada la base (de tipo double) y el exponente
 * (entero), y devuelva el valor de dicha potencia (En no más de 10 líneas).
 *
 * Por ejemplo, potencia(2,-4) debe devolver 0.0625. En caso de no poder calcularse el resultado debe devolver –1
 */

#include <stdio.h>
#include "/home/uriel/PI/getnum.h"
#include <math.h>

#define         EPSILON     0.0000000001

double pot(double, int);

int main()
{
    double a = getdouble("");
    int b = getint("");
    
    printf("%g", pot(a,b));
    return 0;
}

// Disclaimer: no hay chance que se me haya ocurrido lo de fabs xd.
double pot(double base, int exp) 
{
    if (exp < 0) {
        exp = -exp;
        base = 1.0/base;
    } 

    if (exp == 0 && (fabs(base) != 0)) {
        return 1;
    } else if (exp == 0 && (fabs(base) < EPSILON)) {
        return -1;
    }

    for (double aux = base ; exp > 1 ; exp--) {
        base *= aux;
    } 
    return base;
}
