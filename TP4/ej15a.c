/* Biblioteca  para obtener el mayor de 3 numeros */

#include "ej15a.h"

static int fAuxiliar (int m, int n)
{
	int resp;
	
	if ( m > n )
		resp = m;
	else
		resp = n;

	return resp;
}	

int
mayor3 (int n, int m, int p)
{
	return fAuxiliar( fAuxiliar(n,m), p);
}


