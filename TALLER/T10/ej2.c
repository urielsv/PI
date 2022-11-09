/* igualesRet */
/* igualesVoid */

#include <stdio.h>

int igualesRet(const int v1[], const int v2[]);
void igualesVoid(const int v1[], const int v2[], int * igualdad);

int main() 
{
    int v1[] = {1,2,3,4,5,-1};
    int v2[] = {2,3,-1};
    int v3[] = {1,2,3,4,5,-1};
    int v4[] = {-1};
    int igualdad;
    igualesVoid(v4, v4, &igualdad);
    printf("%d\n%d", igualesRet(v4, v4), igualdad);
    return 0;
}

int igualesRet(const int v1[], const int v2[]) 
{
    if (*v1 == -1 && *v2 == -1)
        return 1;
    else if (*v1 != *v2)
        return 0;
    else return igualesRet(v1+1, v2+1);
}

void igualesVoid(const int v1[], const int v2[], int * igualdad)
{
    if (*v1 == -1 && *v2 == -1) {
        *igualdad = 1;
    }
    else if (*v1 != *v2) {
        *igualdad = 0;
    }
    else {
        igualesVoid(v1+1, v2+1, igualdad);
        *igualdad = 1;
    }

}
