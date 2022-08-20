/*
 * Leer un carácter e imprimirlo en mayúscula. Considerar que el 
 * conjunto de caracteres es el del lenguaje inglés, o sea ignorar 
 * la ñ  y vocales acentuadas. (Usar operador condicional).
 */

#include <stdio.h>

#define LOW_TO_UPPER    32

int main() {

    char char1;
    char1 = getchar();

    printf("%c", (char1 >= 'A' && char1 <= 'Z') ? char1 : char1 - LOW_TO_UPPER);

    return 0;
}
