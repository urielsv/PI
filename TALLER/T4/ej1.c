/*
 * Escribir una función numerosAmigos que acepte como parámetro dos 
 * númerosenteros y devuelva en su nombre:
 * 
 * El valor 1 si los números son amigos, esto es si cada uno de ellos es igual 
 * lasuma de los divisores del otro (No se suma el mismo número)
 * 
 * El valor 0 en caso contrario.
 */
#include <stdio.h>
#include <assert.h>

int numerosAmigos(int, int);
int divisores(int);
static int checkAmigos(int, int);
int main(void) {
    assert(numerosAmigos(220, 284));
    assert(!numerosAmigos(10, 12));
    printf("OK!\n");
    return 0;
}

int numerosAmigos(int nu1, int nu2)
{
    return checkAmigos(nu1, nu2) && checkAmigos(nu2, nu1);
}

static int checkAmigos(int n1, int n2)
{
    int sonAmigos = 1, suma = 1;
    for (int i=2; i <= n2/2 && sonAmigos; i++) {
        if (suma > n1) {
            sonAmigos=0;
        } else if (n2 % i == 0) {
            suma += i;
        }
    }
    return sonAmigos && suma == n1;
}
