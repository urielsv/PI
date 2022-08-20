/*
 * Leer dos caracteres desde la entrada estándar e imprimir por salida estándar
 * si son iguales, si el primero es mayor o si el primero es menor, teniendo 
 * en cuenta su valor ASCII. (En no más de 15 líneas).
 *
 * Ejemplo: si se ingresa 'a', 'g', debe imprimir
 * El caracter 'a' es menor al caracter 'g'.
 */

#include <stdio.h>

int main()
{
    char char1, char2;

    char1 = getchar();
    char2 = getchar();

    if (char1>char2) {
        printf("El caracter \'%c\' es mayor que \'%c\'\n", char1, char2);
    } else if (char1<char2) {
        printf("El caracter \'%c\' es menor que \'%c\'\n", char1, char2);
    } else {
        printf("Los caracteres son iguales\n");
    }

    return 0;
}
