/*
 * Dado el siguiente código explicar DETALLADAMENTE el resultado 
 * obtenido al ejecutarlo.
 */

#include <stdio.h>

int
main(void)
{
float a = 0.1;
if (a == 0.1) // no se va a dar nunca pues float 0.1 tiene un error decimal, por
              // lo que seria algo como "0.10000000000129390192 (basura).
printf("SON iguales\n");
else
printf("NO SON iguales: a vale %g que no es igual a 0.1\n",a); // printearia
                                                               // esto y tiraria
                                                               // un valor de
                                                               // 0.1 con un
                                                               // error, lo cual
                                                               // no es 0.1-
                                                               // unicamente
                                                               // (por la
                                                               // basura).
return 0;
}

