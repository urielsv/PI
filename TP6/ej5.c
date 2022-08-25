/*
 * Difficulty: ***
 *
 * Implementar la función anterior para vectores ordenados. 
 */
#include <stdio.h>
#include <assert.h>

int noConsecRepeat(const int arr[], unsigned int dim, int noReapArr[]);

#define ARR_LEN(x)      (sizeof((x))/sizeof((x)[0]))
int main()
{

    int v[] = {1, 2, 3, 3, 4, 5, 5, 8, 14};
    int res[20];
    int dimRes = noConsecRepeat(v, ARR_LEN(v), res);
    for(int i=0; i < dimRes;i++)
        printf("%d. %d\n", i, res[i]);
    
    return 0;
}

// Como esta ordernado, yo se que el siguiente va a ser mayor o igual. Asi que
// solo tomo como referencia el mismo y siguiente.
//
int noConsecRepeat(const int arr[], unsigned int dim, int noReapArr[])
{
    unsigned int newDim = 0;
    for (int i = 0; i < dim; i++) {
        if (arr[i] != arr[i+1])
            noReapArr[newDim++] = arr[i];  
    }
    return newDim;
}
