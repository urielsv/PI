/*
 * Escribir una función que reciba un string con el formato 'dd/mm/yyyy' 
 * que representa una fecha y devuelva en tres parámetros de salida el número 
 * de día, el número del mes y el año. En caso de que la fecha no sea correcta 
 * retorna el valor cero y no altera los parámetros recibidos, 
 * caso contrario retorna 1. 
 * (Ninguna función debe superar las 8 líneas).
 */

#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


typedef unsigned int uInt;


/* Recibe un string con el formato dd/mm/yyyy y retorna por parámetro el día, mes
** y año de la misma. En caso de que el formato sea inválido
** o la fecha incorrecta, retorna FALSE y no altera los parámetros
*/
int valorFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio);
int esBisiesto(uInt anio);
int formatoValido(const char * fecha);
int fechaValida(const char * fecha, uInt *dia, uInt *mes, uInt *anio);

int main(void) 
{
    unsigned int d=100, m=200, a=300;
    int res;
    res = valorFecha("", &d, &m, &a);
    assert(res==0);
    assert(d==100);
    assert(m==200);
    assert(a==300);

    res = valorFecha("29/02/1999", &d, &m, &a);
    assert(res==0);
    assert(d==100);
    assert(m==200);
    assert(a==300);

    res = valorFecha("30/14/2020", &d, &m, &a);
    assert(res==0);
    assert(d==100);
    assert(m==200);
    assert(a==300);

    res = valorFecha("12/12/", &d, &m, &a);
    assert(res==0);
    assert(d==100);
    assert(m==200);
    assert(a==300);

    res = valorFecha("1/1/2000", &d, &m, &a);
    assert(res==0);
    assert(d==100);
    assert(m==200);
    assert(a==300);

    res = valorFecha("12/01/2000", &d, &m, &a);
    assert(res==1);
    assert(d==12);
    assert(m==1);
    assert(a==2000);

    res = valorFecha("29/02/1900", &d, &m, &a);
    assert(res==0);
    assert(d==12);
    assert(m==1);
    assert(a==2000);

    res = valorFecha("29/02/2000", &d, &m, &a);
    assert(res==1);
    assert(d==29);
    assert(m==2);
    assert(a==2000);

    printf("OK");
    return 0;
}

static int diasBis[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                        {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int esBisiesto(uInt anio) 
{
    return (anio % 400 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

int formatoValido(const char * fecha)
{
    int valid = 1;
    valid = (fecha[2] == '/' && fecha[5] == '/' && strlen(fecha) == 10);

    for (int i=0; fecha[i] && valid; i++) {
        if (i != 2 && i != 5 && !isdigit(fecha[i]))
            valid = 0; 
    }
    return valid;
}

int fechaValida(const char * fecha, uInt *dia, uInt *mes, uInt *anio)
{
    int valid = 1;
    *dia = atoi(fecha);
    *mes = atoi(fecha+3);
    *anio= atoi(fecha+6);

    valid = (*dia >= 1 && *dia <= 31 && *mes >= 1 && *mes <= 12);
    
    if (valid) {
        *dia = (*dia >= 28 ? diasBis[esBisiesto(*anio)][*mes-1] : *dia);
    }
    return valid;
}

int valorFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio)
{
    uInt rDia, rMes, rAnio; 
    int valid = 1;
    valid = (formatoValido(fecha) && fechaValida(fecha, &rDia, &rMes, &rAnio));

    if (valid) {
        *dia = rDia;
        *mes = rMes;
        *anio = rAnio;
    }
    return valid;

}
