/*
 * Escribir la función elimina1 que reciba como único argumento un string (vector de chars null terminated) 
 * formado por letras y espacios y elimine del mismo las palabras de una sola letra. Se asegura que el string 
 * sólo contiene letras y espacios, no es necesario validarlo.
 */

#include <stdio.h>
#include <ctype.h>

void elimina1(char * str);

int main()
{

    char s1[] = "a B C  d";
    elimina1(s1);
    printf("%s", s1);
    return 0;
}

void elimina1(char str[]) 
{
    int k = 0;
    for (int i = 0; str[i]; i++) {
        
        if (isalpha(str[i]) && !((i == 0 || str[i-1] == ' ') && (str[i+1] == 0 || str[i+1] == ' '))) {
            str[k++] = str[i];
        } 
        else 
            if (!(isalpha(str[i]))) {
                str[k++] = ' ';
            }
    }
    str[k] = '\0'; 
}
