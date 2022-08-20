/*
 * Leer dos caracteres seguidos de la entrada estándar e imprimir en la
 * salida estándar si son iguales, si el primero es mayor o si el primero
 * es menor, utilizando operadores condicionales:
 *   a)  desde teclado, hacia pantalla
 *   b)  redireccionando la entrada desde archivo, hacia pantalla
 *   c)  desde teclado, redireccionando la salida a  un archivo
 *   d)  redireccionando la entrada y la salida con archivos
 */

#include <stdio.h>

int main() {

   char char1, char2;
   char1 = getchar();
   char2 = getchar();

   printf("%s\n", char1 == char2 ? "Son iguales" : (char1 > char2 ? "El primero es mayor" : "El segundo es mayor"));

   return 0;
}
