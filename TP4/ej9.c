/*
 * La siguiente función recibe como parámetros de entrada las horas y los minutos que 
 * representan el momento de ingreso al trabajo de un empleado, y devuelve 1 ( verdadero ) 
 * si el empleado llegó a horario y 0 ( falso ) si llegó tarde. Las constantes ENT_HORA 
 * y ENT_MINUTOS están definidas fuera de la función e indican el horario esperado de entrada al trabajo.   
 * Testearla, y de no funcionar correctamente, corregirla.
 */

#include <stdio.h>


#define     ENT_HORA    8
#define     ENT_MINUTOS 30

int llegaTemprano (const unsigned int hora, const unsigned int minutos)
{
    if ( (hora < 0 || hora >=24) || (minutos < 0 || minutos >= 60) ) {
        printf("Parametro invalido\n"); 
        return 0;
    }

    return (hora < ENT_HORA || (hora == ENT_HORA && minutos <= ENT_MINUTOS));
}

int main() 
{
    printf("%d\n", llegaTemprano(7,500));
    return 0;
}
