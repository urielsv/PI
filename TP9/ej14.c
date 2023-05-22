/*
Ejercicio 14
    Similar al ejercicio 12 pero el string contiene únicamente paréntesis y debe 
    retornar cero sólo si los paréntesis están apareados. Consideramos que los 
    paréntesis de una expresión están apareados si para cada paréntesis de apertura 
    hay uno de cierre en una posición posterior. No definir macros ni funciones 
    auxiliares.
*/

#include <stdio.h>
#include <assert.h>

int apareadosRec(const char * texto, int bal)
{
    if (*texto == 0 || bal < 0) return bal;

    if (*texto == '(') return apareadosRec(texto + 1, bal + 1);
    if (*texto == ')') return apareadosRec(texto + 1, bal - 1);

    return 0;
}

int apareados(const char *texto)
{
    return apareadosRec(texto, 0);
}

int main(void) {

  assert(apareados("")==0);
  assert(apareados("()")==0);
  assert(apareados("(())()(()())")==0);
  assert(apareados("((((()))))")==0);

  assert(apareados("(")!=0);
  assert(apareados(")")!=0);
  assert(apareados("(")!=0);
  assert(apareados("())")!=0);
  assert(apareados("()(")!=0);
  assert(apareados("((()))())(")!=0);
  
  printf ("OK!\n");
  return 0;
}