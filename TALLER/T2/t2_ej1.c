/*
 * Completar el programa de manera tal que permita separar 
 * los 8 bits de la variable var de a pares, en 4 variables 
 * char distintas trasladando los bits a la posición menos significativa.
 */
#include <stdio.h>

#define     MASK       0x03
int main()
{
    char char_in, var1, var2, var3, var4;
    char_in = getchar();
    // 0xD8 = 1101 1000
    
    var1 = (char_in >> 6) & MASK; // 11 = 3
    var2 = (char_in >> 4) & MASK; // 01 = 1 
    var3 = (char_in >> 2) & MASK; // 10 = 2
    var4 = (char_in) & MASK; // 00 = 0
    
    printf("D: %d\nV1: %d\nV2: %d\nV3: %d\nV4: %d\n", char_in, var1, var2, var3, var4);
    
    return 0;
}
