// Hacer el 2 pero con getchar();
#include <stdio.h>

int main()
{
    
    int isComa = 0; // si es coma o punto.
    int num, suma_digs = 0;

    do {
        num = getchar();
        if (num == '.' || num == ',')
            isComa = 1;
        else if (isComa) {
            suma_digs += (num - '0');
        }
    } while ((num >= '0' && num <= '9') || num == '.' ||
                num == ',' || num == '-');

    printf("%d\n", suma_digs);
    return 0;
}
