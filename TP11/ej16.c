/*
 * a) La información de alumnos de los cursos activos (los del cuatrimestre) de una
 * universidad, donde se sabe que todos los cursos tienen un cupo máximo de 50
 * alumnos. Los accesos más comunes serán por Nombre del curso, y para un curso
 * por legajo de alumno (para buscar un alumno se indica nombre de curso y legajo).
 */

#define MAX_ALUMS 50

typedef struct tAlums {
    char nombre[20];
    unsigned int legajo;
} tAlums;

typedef struct tCurso {
    char nombre[20];
    tAlums alumnos[MAX_ALUMS];
} tCurso;

typedef struct alumsCDT {
    tCurso * curso;
} alumsCDT;

#undef MAX_ALUMS

/*
b) Los horarios que cursa un alumno de una universidad, distinguiendo por materia.
*/

typedef struct tHor {
    unsigned int hora[24];
    char isEmpty[24];    
} tHor;

typedef struct tMat {
    char * name;
    tHor disp;
    struct tMat * next;
} tMat;

typedef struct tAlu {
    char * name;
    tMat * firstMat;
    
} tAlu;

typedef struct horAluCDT {
    int * m[5]; // Segun marcelo lo haria con una matriz de 5 columnas, no se
                // como meterias todo adentro?
} horAluCDT;

/*
c) Un restorán necesita saber, al cabo de un año, cuánto facturó día por día.
*/

typedef struct restoCDT {
    int factu[365];
} restoCDT;

/*
d) Una computadora tiene conectado un termómetro, y cada vez que la temperatura
supera un determinado umbral (por ejemplo 40 grados centígrados) debe registrar la
hora en que superó ese umbral y la hora en que volvió a bajar (por ejemplo: si a las
8:10 pasó los 40 grados y a las 9:23 la temperatura descendió por debajo de los 40
grados, tendría que haber una entrada con los valores {8:10, 9:23})
*/

struct meds {
    int ini;
    int fin;
};

typedef struct node {
    struct meds timings;
    struct node * next;
} TNode;

typedef struct tempCDT {
    unsigned int umbral;
    TNode * first;
    TNode * last;
} tempCDT;
