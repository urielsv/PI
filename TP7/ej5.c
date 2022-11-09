#include <assert.h>
#include <stdio.h>
#include <string.h>

// Cambiar de acuerdo al tipo elegido 
// Si usan "matriz" de chars debe quedar
// typedef char TAlumnos[MAX_ALUMNOS][MAX_LARGO];   

// Si usan vector de punteros a char debe quedar
// typedef char * TAlumnos[MAX_ALUMNOS];

#define MAX_ALUMNOS 80
#define MAX_NOMBRE  20
typedef char TAlumnos[MAX_ALUMNOS][MAX_NOMBRE];
typedef char TCurso[];

void separaCursos(TAlumnos alums, TCurso curso, TAlumnos cu1, TAlumnos cu2);

int main(void){

    TAlumnos alumnos={"Juan", "Pedro", "Martin", ""}, cursoG, cursoH;
    TCurso curso = {'H', 'G', 'H', 0};
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[1]));
    assert(!strcmp(cursoH[0], alumnos[0]));
    assert(!strcmp(cursoH[1], alumnos[2]));
    assert(!strcmp(cursoG[1], alumnos[3]) && !strcmp(cursoH[2], alumnos[3])); 

    alumnos[0][0] = 0; 
    curso[0]=0;  
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[0]) && !strcmp(cursoH[0], alumnos[0]));

    puts("OK!");
    return 0;
}

void separaCursos(TAlumnos alums, TCurso curso, TAlumnos cu1, TAlumnos cu2)
{
   
    /* Uso el tip de que la memoria es contigua entoncs puedo representarlo como
     * un string largo. */
    unsigned int ctr1 = 0, ctr2 = 0;
    for (int i = 0; alums[i][0]; i++) {
        if (curso[i] == 'G') {
            strcpy(cu1[ctr1++], alums[i]);
        } else {
            strcpy(cu2[ctr2++], alums[i]);
        }
    }

    cu1[ctr1][0] = 0;
    cu2[ctr2][0] = 0;
    

}
