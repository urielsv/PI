/* recMinMax */

#include <stdio.h>

void recMinMax (const int v[], unsigned int dim, int * min, int * max);

int main()
{

    int v[] = {3,1,5,2,6,99,-1,2};
    int min, max;
    recMinMax(v,6,&min,&max);
    printf("%d,%d\n", min, max);
    recMinMax(v,8,&min,&max);
    printf("%d,%d\n", min, max);
    recMinMax(v,0,&min,&max);
    printf("%d,%d\n", min, max);
    return 0;
}


void recMinMax (const int v[], unsigned int dim, int * min, int * max)
{
    if (dim == 0) {
        *min = 0;
        *max = 0;
        return;
    }
    if (*v <= 0) {
        *min = -1;
        *max = -1;
        return;
    }
    
    recMinMax(v+1, dim-1, min, max);
    if (*min == -1)
        return;
    if (*min == 0) {
        *min=*max=*v;
        return;
    }
    
    if (*min > *v)
        *min = *v;
    if (*max < *v)
        *max = *v;  
}
