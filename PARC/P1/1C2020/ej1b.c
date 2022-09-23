/*
 * Escribir una macro TO_LOWER que dada una variable que representa el valor ASCII 
 * de una mayúscula la convierta a minúscula, y si no representa una mayúscula no la modifique.
 */
#include <stdio.h>

#define DELTA           ('a' - 'A')
#define TO_LOWER(c)     ((c) >= 'A' && (c) <= 'Z' ? c += DELTA : (c))

int main() 
{
    
    int c = 'a';
    TO_LOWER(c);
    printf("%c", c);
    c = 'A';
    TO_LOWER(c);
    printf("%c", c);
    c = '#';
    TO_LOWER(c);
    printf("%c", c);
    TO_LOWER(c+1);

    return 0;
}
