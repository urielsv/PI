#include <stdio.h>
#include <string.h>
#include <assert.h>

int comprimeCar(char s[], char c, int arr[], int tam);
 
// Sólo para testing
static void assertArrayEquals(const int * e, const int * a, size_t d);
 
int
main(void) {
    int vec[10];
 
    char s1[20] = "Aaa, bb aaaa cc aaa";
    int dim = comprimeCar(s1, 'a', vec, 10);
    assert(strcmp(s1, "Aa, bb a cc a") == 0);
    assert(dim == 3);
    int expectedS1[] = {1,3,2};
    assertArrayEquals(expectedS1, vec, dim);
 
    char s2[20] = "Aaa bb aaaa cc aaa";
    dim = comprimeCar(s2, 'a', vec, 2);
    assert(strcmp(s2, "Aa bb a cc aaa") == 0);
    assert(dim == 2);
    int expectedS2[] = {1,3};
    assertArrayEquals(expectedS2, vec, dim);
 
    char s3[] = "Aaaaa babaaa aaaaaa";
    dim = comprimeCar(s3, 'a', vec, 5);
    assert(strcmp(s3, "Aa baba a") == 0);
    assert(dim == 4);
    int expectedS3[] = {3,0,2,5};
    assertArrayEquals(expectedS3, vec, dim);
 
    char s4[] = "Aaaaa babaaa aaaaaa";
    dim = comprimeCar(s4, 'a', vec, 2);
    assert(strcmp(s4, "Aa babaaa aaaaaa") == 0);
    assert(dim == 2);
    int expectedS4[] = {3,0};
    assertArrayEquals(expectedS4, vec, dim);
 
    // Sin el caracter a comprimir
    char s5[] = "Aaaaa babaaa aaaaaa";
    dim = comprimeCar(s5, 'z', vec, 2);
    assert(strcmp(s5, "Aaaaa babaaa aaaaaa") == 0);
    assert(dim == 0);
 
    // Con el caracter pero sin tamaño
    char s6[] = "Aaaaa babaaa aaaaaa";
    dim = comprimeCar(s6, 'a', vec, 0);
    assert(strcmp(s6, "Aaaaa babaaa aaaaaa") == 0);
    assert(dim == 0);
 
    char s7[] = "";
    dim = comprimeCar(s7, 'a', vec, 10);
    assert(strcmp(s7, "") == 0);
    assert(dim == 0);
 
    printf("OK!\n");
    return 0;
}
 
int comprimeCar(char s[], char c, int arr[], int tam)
{
    if (s[0] == 0)
        return 0;

    int k = 0, i = 1, j = 0, ctr = 0;
    for (; s[i] && j < tam; i++) {
        if (s[k] != c) {
            s[++k] = s[i];
        } else if (s[i] == s[k]) {
            ctr++;
        } else { // y no es c
            s[++k] = s[i];
            arr[j++] = ctr;
            ctr = 0;
        }
        
    }
    if (ctr > 0) 
        arr[j++] = ctr;
    while (s[i] != 0) {
        s[++k] = s[i++];
    }
    s[++k] = 0;
    return j;

}
// Sólo para testing
static void
assertArrayEquals(const int * expected, const int * actual, size_t dim) {
    for(int i = 0; i < dim; i++) {
        assert(expected[i] == actual[i]);
    }
}
