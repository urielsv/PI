/*
 * Escribir un programa interactivo para jugar al juego del ahorcado. 
 * Las palabras que almacena la máquina deben estar guardadas en un arreglo 
 * de strings constantes y cada vez que se elija jugar, utilizar aleatoriamente 
 * alguna de dichas palabras.
 * Antes de escribir el programa, realizar el diseño y la modularización, 
 * documentando cada módulo interviniente, tal como se mostró en los ejercicios 8 y 10.
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define VIDAS   6
#define MAX_LEN 20

#define CLR_BUFF    while (getchar() != '\n')

int randWord(char ** palabras[]);
int checkLetter(char palabra[], char letra, char encontradas[]);
int printState(char palabra[], char encontradas[]);
char readLetter();
void ahorcado(char palabra[]);

/* Ejecutar el juego del ahorcado. */
int main() 
{
    /* Se crean palabras "aleatorias" y no importa la capitalizacion. */
    char palabras[][MAX_LEN] = {"Hola", "Test", "Ahorcado", "loL"};


    return 0;
}


/* Se utiliza una funcion con rand para pseudo-alearotizar el juego. */
int randWord(char ** palabras[])
{


}

/* Verifica que la letra ingresada este en la palabra. */
int checkLetter(char palabra[], char letra, char encontradas[])
{
    int flag = 1;
    for (int i = 0; palabra[i] && flag; i++) {
        if (palabra[i] == letra) {
            flag = 0;
            encontradas[i] = 1;
        }
    }
    return flag;
}

/* Printear el estado del ahorcado. */
int printState(char palabra[], char encontradas[]) 
{
    for (int i = 0; palabra[i]; i++) {
        if (encontradas[i])
            putchar(palabra[i]);
        else 
            putchar('_');
        
    }
    putchar('\n');
}

/* Pide lectura de letras que sea valida. */
char readLetter()
{
    char ltr;

    do {
        printf("Ingrese letra: ");
        ltr = tolower(getchar());
        
        if (ltr != '\n') CLR_BUFF;

    } while (!islower(ltr));
    
    return ltr;
}

/* Crea el juego ahorcado, con parametros la palabra del arreglo. */
void ahorcado(char palabra[]) 
{
    char ltr = readLetter();
    char encontradas[MAX_LEN] = {0};
    int estado = checkLetter(palabra, ltr, encontradas);

    printState(palabra, encontradas); 


}
