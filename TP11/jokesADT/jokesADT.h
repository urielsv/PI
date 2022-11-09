#ifndef __jokesADT_h_
#define __jokesADT_h_

typedef struct jokesCDT * jokesADT;

/* Nuevo TAD y recuperar chistes. */
jokesADT newJokes();

void freeJokes(jokesADT jokes);

void addCategory(jokesADT jokes, const char * category);
void addJoke(jokesADT jokes, const char * category, const char * joke);

#endif
