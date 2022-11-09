#include <stdio.h>

int recSum(int v[], unsigned int dim);

int main()
{
    int v[] = {1,2,3,4,5};
    int v1[] = {};
    int su1 = recSum(v, 5);
    int su2 = recSum(v1, 0);

    printf("%d, %d\n", su1, su2);
    return 0;
}
int recSum(int v[], unsigned int dim)
{
    if (dim == 0)
        return 0;
    return v[0] + recSum(v+1, dim-1);
}
