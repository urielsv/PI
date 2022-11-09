#include <stdio.h>

#define DEC_BASE    10

int recSumDigs(int num);

int main()
{
    int su1 = recSumDigs(3498);

    printf("%d\n", su1);
    return 0;
}
int recSumDigs(int num)
{
    if (num <= DEC_BASE)
        return num;

    return (num % DEC_BASE) + recSumDigs(num/DEC_BASE);
}
