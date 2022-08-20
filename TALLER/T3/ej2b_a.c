// Hacer el 2 pero con getchar();
#include <stdio.h>

int main()
{
    
    int isComa = 0; // si es coma o punto.
    int num, sumaDigs = 0;

    while (((num = getchar()) >= '0' && num <= '9') || num == '.' ||
                num == ',' || num == '-') {
        
        if (num == '.' || num == ',')
            isComa = 1;
        else if (isComa) 
            sumaDigs += num - '0'; 
    }
    printf("%d\n", sumaDigs);

    return 0;
}
