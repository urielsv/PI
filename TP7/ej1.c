/*
 * a. Generar el ejecutable para el siguiente programa, primero sin usar el 
 * flag -fsanitize=address y verificar que funcione.
 *
 * b. Volver a generar el ejecutable pero con el flag. ¿Qué sucede al ejecutarlo? 
 * A qué se deben los errores? Es fácil viendo los errores detectar el origen de los mismos?
 * 
 * c. Vuelva a compilar agregando además el flag -g y ejecute nuevamente. 
 * Ahora debería poder ver el origen de algunos errores. Corregir el programa 
 * para que funcione sin errores.
 */
#include <stdlib.h>
#include <stdio.h>

int
main(void) {

    /* Heap buffer overflow es el error */
        char * p = malloc(10);

        /* Estaba asignando en memoria no reservada (por comparacion del <=) */
        for(int i=0; i < 10; i++) {
                p[i] = i * 10;
        }
                    

        /* Estaba asignando en memoria no reservada (por comparacion del <=) */
        for(int i=0; i < 10; i++)
                printf("%d\n", p[i]);

        /* Libero la memoria que asigne en heap */
        free(p);

        return 0;
}


