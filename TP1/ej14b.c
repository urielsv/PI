#include <stdio.h>

#define NRO 019 // Error porque no existe el '9' en sistema octal. 

int
main(void)
{
	long i = NRO;
	printf("%ld\n",i);
	return 0;
}

