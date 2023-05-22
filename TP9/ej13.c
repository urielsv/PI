/*
Ejercicio 13
    Escribir una versión recursiva de la función strrchr.
*/

#include <stdio.h>
#include <string.h>
#include <assert.h>


char * strrchrRec(const char *s, char c)
{
    if (*s == 0) return NULL;

    // Avanzo hasta el final. 
    char * next = strrchrRec(s+1, c);
    else if (next) return next;
    // Retorna la pos si es el c que busco.
    else return (*s == c) ? (char *) s : NULL;
}

int
main(void) {
	char * s = "vamos a buscar";

	for ( int i=0; s[i]; i++) {
		assert(strrchr(s, s[i]) == strrchrRec(s, s[i]));
	} 

	puts("OK!");
}
