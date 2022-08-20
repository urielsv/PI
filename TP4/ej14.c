#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

float f1(float x);
float f2(float x);
float funAuxiliar(float x);

int
main (void)
{
	float x, y, z;
	x= getfloat("Ingrese un número real :");
	putchar('\n');

	y = f1(x);
	z = f2(x);

	printf("El doble absoluto de %g es %g\n",x, y);
	printf("El triple absoluto de %g es %g\n",x , z);
	return 0;
}

