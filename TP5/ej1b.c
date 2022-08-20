#include <stdio.h>

int a, b, c; 

void primero ( void );
void segundo ( void );

int main ( void )
{   
    a = 1;    
    printf("El valor de c es %d\n", c );
    segundo();
    printf ("El valor de a es %d, el de b es %d\n",a , b );
    primero();      
    printf("El valor de a es %d, el de c es %d\n", a, c );

    return 0;
}

void primero ( void )
{     
    a = 3;   
    c = 0;
}
void segundo ( void )
{    
    c = 0;   
    a = 2;   
    b = -a;
}
