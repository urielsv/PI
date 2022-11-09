#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "complex.h"

#define EPS 0.01

int main(void) {
    complexADT comp1 = newComp( 1, 2 ); // comp1 = 1 + 2i
	complexADT comp2 = newComp( 2, -3 ); // comp2 = 2 - 3i
	complexADT ans;

	ans = sumComp( comp1, comp2 );
	assert( getRealComp(ans) - 3 < EPS && getImagComp(ans) + 1 < EPS );
	freeComp( ans );

	freeComp( comp1 );
	freeComp( comp2 );
	freeComp( ans );

	printf("OK!\n");
}
