/*
 * Leer un número entero e indicar cuántos dígitos de 
 * ese número son iguales a 5. Repetir para el caso de 
 * ser un número real, indicando cuántos 5 tiene en 
 * su parte entera y cuántos en su parte decimal. 
 * 
 * (En no más de 10 líneas el primer caso, y no más 
 * de 25 el segundo caso).
 */

#include <stdio.h>

#define     MATCH   '5'

int main()
{
    int num;
    unsigned int counter = 0;

    printf("Ingrese un entero: ");
    
    do {
        num = getchar();
        if(num == MATCH) 
            counter++;
    } while ((num >='0' && num <='9')); 
    printf("Cantidad de cincos: %d", counter);

    return 0;
}
