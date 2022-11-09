/*
 * Escribir la función copiaPrefijo que dado un string s y un número entero 
 * n retorne en su nombre un nuevo string con los primeros n caracteres del 
 * string s. Si la longitud de s es menor a n debe retornar una copia de s. 
 * En caso de que no se pueda copiar debe retornar NULL. ¿Qué cuidado debe 
 * tener el usuario de esta función?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * copiaPrefijo(char * str, unsigned int num);
int main()
{


    return 0;
}

char * copiaPrefijo(char * str, unsigned int num)
{
    char * aux; 

    int slen = strlen(str);
    if (slen <= num)
        return str;

    if ((aux = malloc(slen+1)) == NULL) {
        return NULL;
    }

    int i = 0;
    for (; i < num; i++) {
        aux[i] = str[i];
    }

    aux[i] = 0;
    return aux;
}
