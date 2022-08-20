/*
 * Leer dos caracteres desde la entrada estándar e imprimir 
 * en la salida estándar el de mayor valor ASCII, usando el 
 * operador condicional. Redireccionar la entrada de manera 
 * tal que getchar  lea desde el archivo entrada.txt.  
 * Dicho archivo será escrito con un editor de texto sin formato 
 * y deberá tener el siguiente contenido:
 */

#include <stdio.h>

int main() {

    char char1,char2;

    char1 = getchar();
    char2 = getchar();

    printf("%c", char1>char2 ? char1 : char2);

    return 0;
}
