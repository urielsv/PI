/*
 * Escribir la macro isdigit que dado un caracter  indique si 
 * dicho caracter representa un dígito decimal o no.
 *
 * Ejemplo:
 * int letra;
 * letra = getchar();
 *  if ( isdigit(letra) )
 * printf("Es un dígito\n");
 */

#include <stdio.h>

#define     ISDIGIT(c)      (c>='0' && c<='9') 

int main()
{
    int char1 = getchar();

    if (ISDIGIT(char1)) {
        puts("Es digito");
    } else {
        puts("No es digito");
    }

    return 0;
}
