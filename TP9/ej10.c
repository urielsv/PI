/*
Ejercicio 10
    Escribir una función recursiva que reciba dos parámetros de tipo string, 
    uno de entrada y el otro de salida. La función debe devolver en el 
    segundo string los caracteres del primero en forma invertida. 
    En la primera invocación de esta función recursiva el segundo string debe 
    contener todos los caracteres en cero y con el suficiente espacio como 
    para almacenar al primero, pero no debe validar  estas condiciones.

    Ejemplo:
	
    char origen[] = "Practica";
    char destino[20] = {0};
    invierte(origen, destino);
		
 	Con esta invocación, en  destino  se obtendrá  el string  “acitcarP”.

    Nota: se asume que el vector de entrada no es el mismo que el de salida
*/
#include <stdio.h>
#include <assert.h>
#include <string.h>

/* Version con strlen */
void invierte(char * src, char * dst)
{
    if (*src == 0) return;
    else {
        // Coloco el primer caracter de src en el ultimo de dst.
        dst[strlen(src)-1] = src[0];
        invierte(src + 1, dst);
    }
}

/* Version sin strlen*/
int invierte1(char * src, char * dst)
{
    if (*src == 0) return 0;
    else {
        // Recorre hasta el final de src, haciendo n+1 cada vez.
        // Luego va retornando en los dst[n] la pos de src[0].
        int n = invierte1(src+1, dst);
        dst[n] = src[0];
        return n + 1;
    }
}

int main(void) {

  char s[20] = {0};

  invierte("1234567890", s);
  assert(strcmp(s, "0987654321")==0);

  memset(s, 0, 20);
  invierte("", s);
  assert(strcmp(s, "")==0);

  memset(s, 0, 20);
  invierte("a", s);
  assert(strcmp(s, "a")==0);

  memset(s, 0, 20);
  invierte("ab", s);
  assert(strcmp(s, "ba")==0);
  
  memset(s, 0, 20);
  invierte("abc", s);
  assert(strcmp(s, "cba")==0);

  printf ("OK!\n");
  return 0;
}