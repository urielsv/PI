/*
Ejercicio 8
    Calcular por medio de una función recursiva que reciba como parámetros 
    de entrada dos números enteros mayores o iguales a cero, la fórmula de
    ACKERMANN correspondiente a los mismos, de acuerdo a las siguientes reglas:
       	    
    ACK ( 0,N ) = N + 1
    ACK ( M,0 ) = ACK ( M - 1, 1 )
    ACK ( M,N ) = ACK ( M - 1, ACK ( M , N - 1 ) )
*/
#include <stdio.h>
#include <assert.h>

int ackermann(unsigned int m, unsigned int n) 
{
    if (m == 0) return n + 1;

    else if (n == 0) return ackermann(m - 1, 1);
    else return ackermann(m - 1, ackermann(m, n - 1));
}

int main(void) {

  for(int i=0; i < 100; i++)
     assert(ackermann(0, i)==i+1);

  assert(ackermann(3,0)==5);
  assert(ackermann(3,2)==29);

  printf("Wait for it...\n");

  assert(ackermann(4,1)==65533);

  printf ("Legendary!\n");
  return 0;
}