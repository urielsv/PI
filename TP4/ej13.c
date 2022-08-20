/*
 * Se desea crear un archivo ejecutable en base a dos archivos fuente: 
 * tp4_13a.c y tp4_13b.c. Corregir los errores en cada uno de los archivos 
 * fuente, indicando si son errores de preprocesamiento, compilación o
 * linkedición.
 *
 * Nota: no puede ser parte de la solución contar con un único archivo fuente.
 */

/*
 * Errores: 1. Compilacion, funcion f1 esta definida despues de main sin
 * prototipar.
 * Errores: 2. Linkedicion. No esta prototipada f2 por lo que no se detecta la
 * funcion al linkeditar.
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

float f1 (float x);
float f2 (float x);
int
main (void)
{
	float x, y, z;
	x= getfloat("Ingrese un número real :");
	putchar('\n');

	y = f1(x);
	z = f2(x);

	printf("El doble de %g es %g\n",x, y);
	printf("El triple de %g es %g\n",x , z);
	return 0;
}

float
f1 ( float x)
{
	return 2 * x;
}


