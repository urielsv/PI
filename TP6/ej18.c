/*
 * Una fila es amiga de otra si todos los elementos de una fila 
 * están incluidos en otra. Por ejemplo:
 * 
 * F1= 1 2 2 3 
 * F2= 0 1 2 3 
 * F3= 1 2 3 4 
 *
 * F1 es amiga de F2 pues todos los elementos de F1 están incluidos en F2
 * F2 no es amiga de F1 pues el número 0 presente en F2 no está incluido en F1
 * F1 es amiga de F3 pues todos los elementos de F1 están incluidos en F3
 * F3 no es amiga de F1 porque el número 4 presente en F3 no está incluido en F1
 *
 * Una matriz es amiga de otra si todas las filas de la primera matriz son 
 * amigas de alguna fila de la segunda matriz.
 * 
 * M1 es amiga de M2 pues
 * la fila 0 1 2 3 de M1 es amiga de la fila 0 1 2 3  de  M2 
 * la fila 4 4 5 6 de M1 es amiga de la fila 4 5 6 8  de  M2
 * la fila 7 8 8 9 de M1 es amiga de la fila -3 7 8 9  de  M2
 * M2 no es amiga de M1 pues la fila -3 7 8 9   de M2 no es amiga de ninguna de las filas de  M1
 * M1 no es amiga de M3 pues la fila 0 1 2 3   de M1 no es amiga de ninguna de las filas de  M3
 * M3 no es amiga de M1 pues la fila 2 3 3 7   de M3 no es amiga de ninguna de las filas de  M1
 *
 * Se pide escribir la función sonAmigas que reciba los siguientes parámetros:
 * m1: la primera matriz de enteros 
 * fils1: la cantidad de filas de la primera matriz de enteros
 * m2: la segunda matriz de enteros
 * fils2: la cantidad de filas de la segunda matriz de enteros
 */

#include <stdio.h>
#include <assert.h>

#define COLS 4

int sonAmigas(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 );
static int filasAmigas(const int v1[], const int v2[]);
static int amistad(const int (m1[])[COLS], unsigned int fils1, const int (m2[])[COLS], unsigned int fils2 );
static int totalAmistad(const int m1[][COLS], unsigned int fils1, const int m2[][COLS], unsigned int fils2);

int main(void)
{
    int m1[][COLS] = {{0,1,2,3}, 
                      {4,4,5,6}, 
                      {7,8,8,9}};

    int m2[][COLS] = {{0,1,2,3}, 
                      {-3,7,8,9}, 
                      {-1,3,4,7}, 
                      {4,5,6,8}};

    int m3[][COLS] = {{2,3,3,7}};

    assert(sonAmigas(m1,3,m2,4)==1);
    assert(sonAmigas(m1,1,m2,4)==1);
    assert(sonAmigas(m1,2,m2,4)==1);
    assert(sonAmigas(m1,2,m2,2)==0);
    assert(sonAmigas(m2,4,m1,3)==2);
    assert(sonAmigas(m1,3,m3,1)==0);
    assert(sonAmigas(m3,1,m1,3)==0);
    int res = sonAmigas(m1,3,m1,3);
    assert(res==1 || res==2);
    
    printf("OK !\n");

    return 0;
}

static int filasAmigas(const int v1[], const int v2[])
{
    /* Recorrer elementos para checkear que sean validos o amigos */
    int encontro = 0;
    for (int i = 0, j = 0; i < COLS && j < COLS; ) {
          
        if (v1[i] < v2[j])
            return 0;

        if (v1[i] == v2[j])
            i++;
        else 
            j++;
        
        encontro = (COLS == i);
    } 
    return encontro;
}

static int amistad(const int (m1[])[COLS], unsigned int pos1, const int (m2[])[COLS], unsigned int fils2 )
{
    /* Checkear que la fila X sea amiga de alguna otra */
    int amistad = 0;
    for (int j = 0; j < fils2 && !amistad; j++) {  
            amistad = filasAmigas(m1[pos1], m2[j]);
    }
    return amistad;
}

static int totalAmistad(const int m1[][COLS], unsigned int fils1, const int m2[][COLS], unsigned int fils2) 
{
    int amis = 0;
    for (int i = 0; i < fils1; i++) {
        amis = amistad(m1, i, m2, fils2);
        if (!amis)
            return 0;
    }
    return 1;
}

int sonAmigas(const int (m1[])[COLS], unsigned int fils1, const int (m2[])[COLS], unsigned int fils2 )
{
    int amistad1, amistad2;

    amistad1 = totalAmistad(m1, fils1, m2, fils2);
    amistad2 = totalAmistad(m2, fils2, m1, fils1);
    
    if (amistad1)
        return 1;
    if (amistad2)
        return 2;

    return 0;
}


