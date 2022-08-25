/*
 * Difficulty: **_
 *
 * Escribir una función que reciba un vector desordenado de números enteros 
 * y su dimensión, y construya otro vector eliminando los valores repetidos. 
 * La función deberá retornar en su nombre la dimensión del nuevo vector 
 * (La función solicitada  no debe superar las 10 líneas).
 */
#include <stdio.h>
#include <assert.h>

int noRepeatElems(const int arr[], unsigned int dim, int noReapArr[]);

int main()
{

    int v[] = { 3, 5, 1, 3, -3, 3, 5, 1};
    int res[20];
    int dimRes;
    dimRes = noRepeatElems(v, 0, res);
    assert(dimRes==0);
 
    dimRes = noRepeatElems(v, 8, res);
    assert(dimRes==4);
    assert(res[0]==3);
    assert(res[1]==5);
    assert(res[2]==1);
    assert(res[3]==-3);
    
    return 0;
}

int noRepeatElems(const int arr[], unsigned int dim, int noReapArr[])
{
    unsigned int newDim = 0;
    int isDup;
    for (int i = 0; i < dim; i++, isDup = 0) {
        
        for (int j = 0; !isDup && j < newDim; j++)
            if (arr[i] == noReapArr[j])
                isDup = 1; 
        
        if (!isDup) 
            noReapArr[newDim++] = arr[i];  
    }

    return newDim;
}
