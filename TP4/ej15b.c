/* Biblioteca para obtener el promedio de 3 enteros */

#include "ej15b.h"
 
static int fAuxiliar (int n, int m, int p)
{
	return n + m + p;
}

float
promedio3 (int n, int m, int p)
{
	return fAuxiliar(n,m,p) / 3.0;
}

