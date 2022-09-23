/* 
 * Hacer una función que reciba como único parámetro de entrada/salida 
 * un string y elimine los espacios de más.  Por ejemplo, si recibe 
 * Hola           mundo      , deberá transformarlo en Hola mundo
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>

void eliminaEspacios(char str[]);

int main(void) {
  char s[60] = "   "; // cant impar de blancos
  eliminaEspacios(s);
  assert(strcmp(s, " ")==0);

  eliminaEspacios(s);
  assert(strcmp(s, " ")==0);

  strcpy(s,"  ");
  eliminaEspacios(s);
  assert(strcmp(s, " ")==0);
  
  strcpy(s," . . .  ");
  eliminaEspacios(s);
  assert(strcmp(s, " . . . ")==0);

  strcpy(s,"");
  eliminaEspacios(s);
  assert(strcmp(s, "")==0);

  strcpy(s,"sinblancos");
  eliminaEspacios(s);
  assert(strcmp(s, "sinblancos")==0);



  printf("OK!\n");
  return 0;
}

void eliminaEspacios(char str[])
{
    int j = 1;
    for (int i = 1; str[i]; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        } else if (str[i] != str[i-1]) {
            str[j++] = ' ';
        }
    } 
    str[j] = 0;
}

