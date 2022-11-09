/*
 * Una partícula realiza un camino aleatorio dentro de un círculo 
 * de acuerdo a la siguientes reglas :
 *
 * En tiempo t = 0 la partícula está en el centro ( x = 0, y = 0).
 *
 * La partícula hace un paso aleatorio en una de las cuatro direcciones dada por
 * x = x - 1
 * x = x + 1
 * y = y - 1
 * y = y + 1
 *
 * La caminata termina cuando se sale fuera del círculo ( x2 + y2>= r2 ).
 *
 * Considerando cada punto como una estructura de componentes cartesianas y 
 * teniendo en cuenta que el tiempo se mide con un contador que se incrementa  
 * en cada paso de la partícula, escribir un programa que para distintos tamaños 
 * de círculos determine experimentalmente la relación entre el tiempo requerido 
 * para terminar la caminata y el valor del radio.
 *
 * Mostrar los valores hallados mediante una tabla cuyas columnas sean:
 * Radio
 * Tiempo
 * Relación (radio / tiempo )
 */

#include <stdio.h>
#include "/home/uriel/PI/random.h"
#include <stdbool.h>

#define X_INIT  0
#define Y_INIT  0
#define MIN_RAD 10
#define MAX_RAD 100

typedef struct TPart {
    int pos_x, pos_y;
} TPart;

typedef unsigned int Timer;

void move(TPart * part);
bool outOfBounds(TPart part, unsigned int rad);
Timer timeToLeave(unsigned int rad);
void createResults();

int main()
{
    randomize();
    /* Creates the simulation. */
    createResults();
    return 0;
}

void move(TPart * part) 
{
    int newPos = randInt(0, 4);
    switch (newPos) {
        case 0:
            part->pos_x--;
            break;
        case 1:
            part->pos_x++;
            break;
        case 2:
            part->pos_y--;
            break;
        case 3:
            part->pos_y++;
    }
}

bool outOfBounds(TPart part, unsigned int rad) 
{
    return (part.pos_x * part.pos_x + part.pos_y * part.pos_y) >= rad;
}

Timer timeToLeave(unsigned int rad)
{
    Timer time = 0;
    TPart part = {X_INIT, Y_INIT};

    do {
        move(&part);
        time++;
    } while (!outOfBounds(part, rad));

    return time;
}

void createResults()
{
    Timer time;
    unsigned int rad; 
    puts("RAD\tTIME\tRATIO");
    for (rad=MIN_RAD; rad <= MAX_RAD; rad += (MAX_RAD-MIN_RAD)/10) {
        time = timeToLeave(rad);
        printf("%d\t%d\t%.2f\n", rad, time, (float) rad/time); 
    }

}


