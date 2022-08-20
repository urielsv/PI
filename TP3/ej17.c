/*
 * Escriba y ejecute un programa que imprima todos los 
 * múltiplos de 10 (10, 20, 30, 40, etc.) en no más 
 * de 5 líneas ¿Qué sucede cuando ejecuta este programa ?
 */

#include <stdio.h>

int main()
{
    for(int i=1;;i++)
        printf("%d\t", i*10);
    return 0;
}
