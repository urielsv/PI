/*
 * Difficulty: **_
 * Se desea calcular la desviación estándar de un arreglo de números enteros. 
 * Los números del arreglo toman valores entre 0 y 15 inclusive, 
 * por lo que para almacenar cada número se utilizarán solo 4 bits, 
 * pudiendo almacenar dos números en un solo byte.
 * promedio, despues sumatoria y despues sqrt sumatoria / cantidad de  numeros.
 */
#include <stdio.h>
#include <assert.h>
#include <math.h>

/* Calcula la desviacion estandar */
double desv(const char vector[], int cantnum );
double average(const char vec[], unsigned int elems);
double sumTotal( double avrg, const char vec[], unsigned int elems);
static int splitFirst(int num);
static int splitSecond(int num);

int main(void)
{
    double d;
    unsigned char arreglo2[] = { 0x33, 0x33, 0x33, 0x33, 0x33 };
    for(int i=0; i <= 10; i++)
        assert(desv(arreglo2, i)==0);
    
    
    unsigned char arreglo[] = { 0x37, 0xF2, 0x03, 0x4A, 0xFF };
    assert(desv(arreglo, 1)==0);
    assert(desv(arreglo, 2)==2.0);
    
    assert(desv(arreglo, 3) > 4.98 && desv(arreglo, 3) < 4.99);
    
    assert(desv(arreglo, 10) > 5.6071 && desv(arreglo, 3) < 5.6072);
    
    puts("OK!");
}

#define MASK    0x0F
#define BYTE    4
static int splitFirst(int num) 
{
    return splitSecond(num >> BYTE);
}

static int splitSecond(int num) 
{
    return num & MASK;
}
#undef MASK
#undef BYTE

double average(const char vec[], unsigned int elems) 
{
   int num1, num2, i = 0, sum = 0; // 0x37, 0x4E
   while ( elems != 0 ) {
        sum += splitFirst(vec[i]);
        elems--;
        if ( elems != 0 )
            sum += splitSecond(vec[i]);
        i++;
   }
   return sum / (double) elems;
}

double sumTotal( double avrg, const char vec[], unsigned int elems)
{
   int num1, num2, i = 0;
   double sum = 0;
   avrg = average(vec, elems);
   while ( elems != 0 ) {
        sum += pow((splitFirst(vec[i]) - avrg), 2);
        elems--;
        if ( elems != 0 )
            sum += pow((splitSecond(vec[i]) - avrg), 2);
        i++;
   }
   return sum;
}

double desv( const char vector[] , int cantnum )
{
    if (cantnum == 0)
        return 0.0;
	double avrg, sum;
    avrg = average( vector , cantnum );
	sum = sumTotal( avrg , vector , cantnum );

    return sqrt(sum/(cantnum-1));
}
