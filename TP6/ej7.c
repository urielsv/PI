/*
 * Hacer una función que reciba dos parámetros de entrada representando 
 * arreglos de números enteros positivos, ordenados en forma ascendente 
 * y sin elementos repetidos. El ultimo elemento de cada arreglo es -1.
 * La función debe devolver en un tercer parámetro de salida un arreglo 
 * ordenado con la unión de los dos primeros, también terminado en -1.
 * 
 * Ejemplo: Dados v1 y v2 arreglos de enteros, se espera que la unión sea:
 *		v1 = {1,2,3,-1} y v2 = {2,3,4,-1}  →  unión = {1,2,3,4,-1}.
 *		v1 = {1,2,3,-1} y v2 = {1,2,3,-1}  →  unión = {1,2,3,-1}.
 */

#include <stdio.h>
#include <assert.h>

void arrUnion( const int arr1[], const int arr2[], int un[]);

void check(const int v1[], const int v2[]) {
  int i;
  for(i=0; v1[i] != -1; i++)
     assert(v1[i]==v2[i]);
  assert(v1[i]==-1);
  assert(v2[i]==-1);
}

int main()
{
  int v1[] = { 1, 5, 15, 30, 35, 45, 55, -1};
  int v2[] = {-1};
  int v3[] = { 1, -1};
  int v4[] = { 2, 3, 15, 16, 33, 35, 45, 65, -1};
  int dimRes;
  int res[30];
  
  arrUnion(v1, v2, res);
  check(v1, res);

  arrUnion(v2, v2, res);
  check(v2, res);

  arrUnion(v1, v1, res);
  check(v1, res);

  arrUnion(v1, v3, res);
  check(v1, res);

  int expected[] = {1, 2, 3, 5, 15, 16, 30, 33, 35, 45, 55, 65, -1};
  arrUnion(v1, v4, res);
  check(expected, res);

  printf("OK!\n");
 
  return 0;
}

#define ARR_STOP -1
void arrUnion( const int arr1[], const int arr2[], int un[])
{

}
#undef ARR_STOP
