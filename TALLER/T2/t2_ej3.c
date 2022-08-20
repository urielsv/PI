/*
 * Completar el programa de manera tal que si las variables a y b 
 * leídas son ambas dígitos, primero los convierta en un único número 
 * en decimal.( Si se leyó ’1’’2’ el número es 12) y luego guarde el 
 * resultado en hexadecimal, en dos variables como caracteres ascii.
 * (Ej 98 = 62, en una variable se guarda ‘6’, en otra ‘2’).
 */

#include <stdio.h>

#define     DEC_BASE        10
#define     HEX_BASE        16
int main() 
{
    int a, b, num, h_num, ahex, bhex;
     
    a = getchar();
    b = getchar();
    
    if ((a>='0' && a<='9') && (b='0' && b<='9')) {
        a -= '0';
        b -= '0'; 
    
        printf("%d%d", a, b);

        ahex = num/HEX_BASE;
        bhex = num%HEX_BASE;
        
        if ( bhex >= 10 )
            bhex = bhex - 10 + 'A';
        printf("Dec: %d\nHexa: 0x%d\n", num, (ahex*10+bhex));
        printf("A_HEX: %c\nB_HEX: %c", ahex, bhex);
    }

    return 0;
}
