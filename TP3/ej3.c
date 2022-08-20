/*
 * Ejercicio 3 - TP3
 *
 * Autor: urielsv @ github.com/urielsv (urielsosavazquez@gmail.com)
 * Fecha: 07/08/22 (DD/MM/YY)
 *
 * Una empresa paga a su personal de venta en base a comisiones.  El personal de 
 * ventas recibe $300 por semana más un porcentaje de las ventas brutas de 
 * esa semana.  El porcentaje a aplicar depende del total vendido: si la venta 
 * no supera los $1000, no hay porcentaje, hasta $2000 es un 5%, hasta 
 * $4000 es un 7%, y más de $4000 es un 9%.
 *
 * Por ejemplo, un vendedor que vende $5000 en una semana, 
 * recibe $300 más 9% de $5000, o sea un total de $750.
 *
 * Hacer un programa en C que lea una única variable que indique la suma vendida 
 * en una semana, e imprima por salida estándar  el monto total a cobrar. 
 * Si la suma vendida es un valor incorrecto pedir un nuevo valor. 
 * (En no más de 15 líneas).
 *
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"

#define     SEMANAL             300
#define     VENTA_MIN           1000
#define     VENTA_MED           2000
#define     VENTA_MAX           4000
#define     VENTA_PORC_MIN      0.05
#define     VENTA_PORC_MED      0.07
#define     VENTA_PORC_MAX      0.09

int main() 
{
    unsigned int venta_sem;
    do { 
    venta_sem = getint("");
    } while ( venta_sem < 0 );
    
    if (venta_sem <= VENTA_MIN) {
        printf("Total a cobrar: %d", SEMANAL);
    } else if (venta_sem > VENTA_MIN && venta_sem <= VENTA_MED) {
        printf("Total a cobrar: %.1f", SEMANAL + venta_sem * VENTA_PORC_MIN);
    } else if (venta_sem > VENTA_MED && venta_sem <= VENTA_MAX) {
        printf("Total a cobrar: %.1f", SEMANAL + venta_sem * VENTA_PORC_MED); 
    } else {
        printf("Total a cobrar: %.1f", SEMANAL + venta_sem * VENTA_PORC_MAX);
    }
    return 0;
}


