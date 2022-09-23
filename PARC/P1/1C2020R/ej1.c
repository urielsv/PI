/*
 * Se tiene una cadena que contiene números decimales separados por coma. 
 * Se requiere implementar la función void normalizar que reciba como único 
 * parámetro un string y lo normalice dejando todos los números con los 
 * decimales truncados a 2. Se asegura que el string está bien formado:
 *
 * 1. Sólo contiene números decimales separados por comas
 * 2. Los números no tienen signo
 * 3. Todos los números tienen al menos un dígito en la parte entera 
 * y un dígito en la parte decimal, separados por un punto.
 */

#include <stdio.h>
#include <ctype.h>

void normalizar(char *);

#define DECIMS  2
int main()
{
    char s1[] = "12.33333,23.44444,1.0054,5.003,7.0";
    normalizar(s1);
    printf("%s\n", s1);
    return 1;
}

void normalizar(char * str) {

    int j = 0, ctr = 0;
    for (int i = 0, prev = str[0]; str[i]; i++) {

        if (i == 0 || prev == ',') {
            
            while(str[i] != '.') 
                str[j++] = str[i++];

        } else if (prev == '.') {
            ctr = DECIMS;
        } 

        if (!isdigit(str[i])) {
            str[j++] = str[i];
        } else if (ctr && str[i]) {
            str[j++] = str[i];
            ctr--;      
        }
        prev = str[i];
    }

    str[j] = '\0';
}

