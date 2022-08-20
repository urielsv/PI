/*
 * Escribir un programa que ofrezca las siguientes opciones para accionar 
 * sobre un caracter leído desde la entrada estándar. Utilizar distintas 
 * funciones (con no más de 4 líneas) para cada una de las opciones y una 
 * función para el menú de opciones:
 * ▪ Convertir de mayúscula a minúscula.
 * ▪ Convertir de minúscula a mayúscula.
 * ▪ Imprimir el carácter siguiente.
 * ▪ Imprimir la siguiente letra en forma circular (si la letra es 'z', debe imprimir 'a')
 */

// Voy a relizar el ejercicio sin usar ctype.

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

#define     DELTA           ('a' - 'A')
#define     ALPHADIFF       ('Z' - 'A')
#define     isMayus(x)      ((x) >= 'A' && (x) <= 'Z')
#define     isMinus(x)      ((x) >= 'a' && (x) <= 'z')

int toLower(char a) 
{
    if (isMayus(a)) {
        return (a + DELTA);
    }
    return a;
}

int toUpper(char a)
{ 
    if (isMinus(a)) {
        return (a - DELTA);
    }
    return a;
}
   
char circChar(char a) {
    int diff; 
    if (isMayus(a)) {
        diff = ALPHADIFF - ('Z'- a);
        return 'Z'- diff; // si es mayus
    } else if (isMinus(a)) {
        diff = ALPHADIFF - ('z' - a);
        return 'z' - diff;
    } else
        return -1;
}

void menu()
{
    printf("\nElija una opcion a utilizar (1-4):\n"
        "1. Convertir de mayus a minus.\n"
        "2. Convertir de minus a mayus.\n"
        "3. Imprimir siguiente caracter.\n"
        "4. Imprimir la letraen forma circular.\n");
    return;
}


int main() 
{
    int a;
    printf("Escriba una letra: "); 
   
    do {
        a = getchar();
    } while (!(isMayus(a) || isMinus(a))); 
 
    menu();
    int opt = getint("");

    switch (opt) {
     case 1:
         printf("%c", toLower(a));
         break;
     case 2:
         printf("%c", toUpper(a));
         break;
     case 3:
         a = getchar();
         printf("%c", a);
         break;
     case 4:
         printf("%c", circChar(a));
         break; 
     default:
         puts("Opcion invalida.");
    } 

   return 0;
}
