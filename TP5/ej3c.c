/*
 * El siguiente programa detecta si un boleto de 5 cifras es capicúa,
 * para ello utiliza una función llamada lugar que dado dos números  
 * n y k, retorna el k-ésimo dígito contando desde la derecha del número n. 
 * Los ceros a izquierda se descartan.
 *
 * a) Agregar una decisión de forma tal que si ingresan un número que 
 * no tenga exactamente 5 dígitos, el programa finalice sin hacer nada.
 *
 * b) Modificar el programa original de forma tal que si ingresa un número 
 * que no sea de 5 dígitos imprima el cartel "Ingreso incorrecto de datos".
 *
 * c) Modificar el programa del punto b) de forma tal que siga leyendo 
 * números hasta que se ingrese un número de exactamente 5 dígitos.
 *
 * d) Modificar el programa original ( sin las correcciones a, b y c ) de 
 * forma tal que sirva para números de cualquier cantidad de cifras 
 * (acotado a números que entren en un int).
 *
 * e) Modificar el programa d) de forma tal que, además de imprimir 
 * el mensaje, devuelva el valor 1 en caso de ser capicúa y 0 
 * en caso de no serlo.
 */

#include <stdio.h>
#include "/home/urielsv/PI/getnum.h"
#include <math.h>

int lugar (int num, int pos);

int main( void )
{
	int boleto, esCapicua=1;
	int j;
    
    do {
	    boleto = getint("Ingrese un número de 5 dígitos:");
    } while (boleto < 10000 || boleto > 99999);

	for (j=1; j<=2; j++) {
		if ( lugar(boleto, j) != lugar(boleto,5-j+1))
		{	
 			esCapicua=0;
			break;
		}
    }
	printf("El boleto %ses capicúa",(esCapicua)? "":"no ");
	return 0;
}

int lugar( int num, int pos )
{		
    return (num / (int)pow(10, pos-1)) % 10;
}
