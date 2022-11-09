#include <stdio.h>
#include <assert.h>
#include "utillist.h"

unsigned int sumAll(const TList l);
int odds1(const TList l);
int odds2(const TList l);

int main()
{
    assert(sumAll(NULL) == 0);
	assert(odds1(NULL) == 1 );
	assert(odds2(NULL) == 0 );

	int v [] = {1, 3, 5, -1, 0, 2, 4, 3};
	TList l1 = fromArray(v, 8);
	assert(sumAll(l1) == 17);
	assert(odds1(l1) == 0);
	assert(odds2(l1) == 0);
	freeList(l1);

	l1 = fromArray(v, 4);
	assert(sumAll(l1) == 8);
	assert(odds1(l1) == 1);
	assert(odds2(l1) == 1);
	freeList(l1);

	l1 = fromArray(v+4, 3);
	assert(sumAll(l1) == 6);
	assert(odds1(l1) == 0);
	assert(odds2(l1) == 0);
	freeList(l1);
	
	puts("OK!");
	return 0;
}

int odds1(const TList l)
{
    if (l == NULL) return 1;
    return l->head % 2 && odds1(l->tail);
}

int odds2(const TList l)
{
    if (l == NULL) return 0;

    if (l->tail == NULL) return l->head % 2;
    return l->head % 2 && odds2(l->tail);

}
unsigned int sumAll(const TList l)
{
    if (l == NULL) return 0;
    return l->head + sumAll(l->tail);
}
