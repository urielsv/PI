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

#define     MATCH       '5'

int main()
{
    int num;
    unsigned int ctr_bef = 0;
    unsigned int ctr_aft = 0;
    unsigned int dot = 0;

    printf("Ingrese un numero: ");
   
    do {
        num = getchar();
        if(num == MATCH && dot == 0) 
            ctr_bef++; 
        else if (num == MATCH && dot == 1)
            ctr_aft++;
         
        if(num == '.')
            dot++;

    } while (((num >= '0' && num <= '9') || num == '.' || num == '-') && dot <= 1);

    printf("#5 (ANTES, DESPUES): %d, %d", ctr_bef, ctr_aft);

    return 0;
}
