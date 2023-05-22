/*
Ejercicio 17
    Se almacena en un string una serie de palabras (secuencias de letras del alfabeto 
    inglés) y la longitud de cada una de ellas. Cada palabra debería tener entre 0 y 9 
    caracteres, por lo que después de cada palabra hay un carácter indicando la longitud 
    de la misma ('4' si tiene 4 letras, '8' si tiene 8 letras, etc.).
 	
    Escribir una función recursiva bienFormado que reciba como único argumento un 
    string con el formato mencionado y retorne 0 (cero) si está bien formado, y distinto 
    de cero si no.
	
    La función no puede usar otras funciones o macros, salvo isdigit e isalpha.
*/

#include <stdio.h>
#include <assert.h>


int main(void) {
 char * zero[]={"abcd4a10bb2", "", "0000", "a1", "abc3", "0a1"};

  char * not_zero[] ={ "a", "1", "a2", "abc2", "abc4", "abc33", "0123", "2aa", "$1", "@@2", "abcd22", "@@"};

  for(int i=0; i < sizeof(zero)/sizeof(zero[0]);i++) {
    printf("%s\n", zero[i]);
    assert(bienformado(zero[i])==0);
  }    

  for(int i=0; i < sizeof(not_zero)/sizeof(not_zero[0]);i++) {
    printf("%s\n", not_zero[i]);
    assert(bienformado(not_zero[i]) !=0);
 }

  puts("OK!");
  return 0;
}