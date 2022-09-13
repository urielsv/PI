/*
 * a) Escribir una función elimina que recibe dos strings y elimina del primero 
 * todos los caracteres que aparecen en el segundo string.
 *
 * Ejemplos de uso:
 * char s[] = "Un string. Con diversas letras y simbolos!!";
 * elimina(s, "aeiou"); // s es ahora "Un strng. Cn dvrss ltrs y smbls!!"
 * elimina(s, " !."); // s es ahora "UnstrngCndvrssltrsysmbls"
 * elimina(s, "aeiou"); // s ahora no cambia
 *
 * b) Escribir un ejemplo de invocación que asegure que el programa aborta 
 * en ejecución. Explicar por qué aborta.
 */

#include <stdio.h>
#include <string.h>

void elimina(char s1[], char s2[]);

int main()
{
    char s[] = "Un string. Con diversas letras y simbolos!!";
    elimina(s, "aeiou"); // s es ahora "Un strng. Cn dvrss ltrs y smbls!!"
    printf("%s\n", s);
    elimina(s, " !."); // s es ahora "UnstrngCndvrssltrsysmbls"
    printf("%s\n", s);
    elimina(s, "aeiou"); // s ahora no cambia
    printf("%s\n", s);
    return 0;
}


void elimina(char * str1, char * str2)
{
    int k = 0;
    for (int i = 0; str2[i]; i++, k = 0) {  
       for (int j = 0; str1[j]; j++) {
           if (str2[i] != str1[j])
               str1[k++] = str1[j];
       }
       str1[k] = '\0';
    }
}
