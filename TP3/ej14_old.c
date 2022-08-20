/*
 * Ejercicio 14 - TP3
 * Autor: urielsv @ github.com/urielsv urielsosavazquez@gmail.com
 * Fecha: 08/08/22 (DD/MM/YY)
 *
 * Leer desde la entrada estándar una serie de caracteres, 
 * hasta que uno de ellos no sea una letra ni un espacio. 
 * Luego imprimir por salida estándar el menor alfabéticamente 
 * de ellos respetando si fue mayúscula o minúscula, 
 * indicando además cuántas letras eran mayúsculas y 
 * cuántas minúsculas. No considerar el carácter ‘ñ’ como letra. 
 * (En no más de 15 líneas).
 *
 * Ejemplo: si se ingresa "Aqui murio Solis" debe imprimir la 
 * letra "A" si se ingresa "Hola mundo" debe imprimir la letra "a"
 */

#include <stdio.h>

int main() 
{
    int char1 = 0;
    int delta = char1;

    do {
        char1 = getchar();
        if(delta<=char1) 
           delta = char1;
 
    } while(char1 == ' ' || 
        (char1 >= 'a' && char1 <='z') ||
        (char1 >='A' && char1 <='Z'));
    printf("%c", delta);
    
    return 0;
}
