/*
 * Leer un caracter desde la entrada estándar e imprimir 
 * en la salida estándar si el mismo es una letra  o no. 
 * Considerar que el conjunto de caracteres es el del lenguaje 
 * inglés, o sea ignorar la ñ  y vocales acentuadas. 
 * Usar el operador condicional.
 */

#include <stdio.h>

int main() {
    
    char char1;
    char1 = getchar();

    printf("%s\n", ((char1 >= 'a' && char1 <= 'b') || (char1 >= 'A' && char1 <='Z')) ? "Es letra" : "No es letra");
          
    return 0;
}
