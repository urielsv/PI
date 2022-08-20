/*
 * Leer un caracter desde la entrada estándar e imprimir 
 * por salida estándar si el caracter es una letra o no y, 
 * en caso de ser una letra, indicar si es letra mayúscula 
 * o minúscula, sin tener en cuenta el caracter ‘ñ’. 
 * (En no más de 15 líneas).
 */

#include <stdio.h>

int main() 
{
    char char1;
    char1 = getchar();

    if (char1 >= 'a' && char1 <='z') { 
        puts("Es minuscula.");
    } else if (char1 >= 'A' && char1 <= 'Z') {
        puts("Es mayuscula.");
    } else {
        puts("No es letra.");
    }
    return 0;
}
