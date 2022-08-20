/*
 * Leer desde la entrada estándar una serie de caracteres, a 
 * hasta que uno de ellos no sea una letra ni un espacio. 
 * Luego imprimir por salida estándar el menor alfabéticamente de
 * ellos respetando si fue mayúscula o minúscula, indicando 
 * además cuántas letras eran mayúsculas y cuántas minúsculas. 
 * No considerar el carácter ‘ñ’ como letra. (En no más de 15 líneas).
 *
 * Ejemplo: si se ingresa "Aqui murio Solis" debe imprimir la letra "A"
 * si se ingresa "Hola mundo" debe imprimir la letra "a".
 */

#include <stdio.h>

int main() 
{
    int char1 = 0;
    int delta = 'z';
    unsigned int low_ctr = 0;
    unsigned int upper_ctr = 0;

    while ( ((char1 = getchar()) == ' ') || 
            (char1 >= 'a' && char1 <= 'z') ||
            (char1 >= 'A' && char1 <= 'Z') ) {
       
        if ( char1>='a' && char1<='z') {
            low_ctr++;
        } else if ( char1>='A' && char1<='Z') {
            upper_ctr++;
        }
        
        if ( (char1 != ' ') && (char1 < delta) )
            delta = char1;
    }
    
    printf("%c\nMINUS: %d\nMAYUS: %d\n", delta, low_ctr, upper_ctr);

    return 0;
}
