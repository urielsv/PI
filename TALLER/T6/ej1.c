#include <stdio.h>
#include <assert.h>

int dondeEsta(const int v[], size_t dim, int num, int ans[]);

int main()
{
    int v[] = {3,5,5,5,5,6,7,7,8,9,12,15};
    int dim = sizeof(v)/sizeof(v[0]);
    int positions[dim];
    int positionsDim = dondeEsta(v, dim, 5, positions);
    for(int i = 0; i < positionsDim; i++) {
        printf("%d ", positions[i]);
    }
 
    assert(positionsDim == 4); // Busco el elemento 5 en v
    assert(positions[0] == 1);
    assert(positions[1] == 2);
    assert(positions[2] == 3);
    assert(positions[3] == 4);
 
    assert(dondeEsta(v, 2, 5, positions) == 1); // Busco el elemento 5 en v con dim 2
    assert(positions[0] == 1);
 
    assert(dondeEsta(v, 1, 5, positions) == 0); // Busco el elemento 5 en v con dim 1
 
    assert(dondeEsta(v, 0, 1, positions) == 0); // Busco el elemento 5 en v con dim 0
 
    assert(dondeEsta(v, dim, 20, positions) == 0); // Busco el elemento 20 en v
 
    printf("\nOK!");
    return 0;
}

int dondeEsta(const int v[], size_t dim, int num, int ans[])
{
    int encontro = 0;
    for (int i = 0; i < dim && v[i] <= num; i++) {
        if (v[i] == num)
            ans[encontro++] = i; 
    }
    return encontro;
}
