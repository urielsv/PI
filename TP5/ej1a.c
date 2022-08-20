#include <stdio.h>

int a,b; 
void local ( void );             
 
int main ( void ) {    
    a = 2; b = 3;
    local();
    printf(" a vale : %d\tb vale %d\n",  a, b );
    
    return 0;
}

void local ( void ) {    

    a = -5;   
    b = 10;
     
    return;

}
