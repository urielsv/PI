/*
 * Escribir un programa (en no más de 15 líneas) para encontrar raíces de funciones en un 
 * intervalo dado. Se deberá recorrer el intervalo a incrementos de 0.001, evaluando la 
 * función en cada paso y escribiendo por salida estándar los puntos que son raíces. 
 * Los extremos del intervalo serán de tipo real y su valor estará dado por constantes del programa. 
 *
 * Tener en cuenta no sólo el caso en el que el resultado de evaluar la función sea cero, 
 * sino también aquellos puntos en los cuales la función cambia de signo.
 *
 * Ejecutar el programa para las siguientes funciones:
 *  sin(x)
 *  cosin(x)
 *  2^x * x^3
 *  sin(x) + log(x)
 *  sqrt(x) + e^x
 */

#include <stdio.h>
#include <math.h>

#define     MATH_FN(x)          (sqrt(x) + exp(x))
#define     L_INTER             -15.0
#define     R_INTER             15.0
#define     EPSILON             0.001
#define     signoCambio(x)      ((MATH_FN(x) > 0 && MATH_FN(x+EPSILON) < 0) ||\
                                (MATH_FN(x) < 0 && MATH_FN(x+EPSILON) > 0) ? 1 : 0)
int main()
{ 
    double intr_left = L_INTER;
    double intr_right = R_INTER;
 
    for (intr_left; intr_left < intr_right ; intr_left += EPSILON) {
        if (signoCambio(intr_left))
            printf("RAIZ: %.4f\n", intr_left);
    }
}
