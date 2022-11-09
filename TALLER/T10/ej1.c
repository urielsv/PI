/* esPotenciaDe3 */

#include <stdio.h>

int esPotenciaDe3(unsigned int num);

int main() 
{
    printf("%d\n", esPotenciaDe3(27)); // 1
    printf("%d\n", esPotenciaDe3(0)); // 0
}

int esPotenciaDe3(unsigned int num)
{
    if (num == 1)
        return 1;
    else if (!(num % 3 == 0 && num != 0))
        return 0;
    else return esPotenciaDe3(num/3);
}
