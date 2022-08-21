#include <stdio.h>

int main()
{
    int lol[] = {1,2,3,4,5,6,7,8,9,0,10,11};

    printf("Size: %d", sizeof(lol)/sizeof(lol[0]));

    return 0;
}
