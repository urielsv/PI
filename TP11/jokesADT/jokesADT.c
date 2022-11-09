#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jokesADT.h"

struct joke {
    char * text;
    size_t len;
};

typedef struct nodeCat {
    char * name;
    size_t len;
    size_t cant; // Cant. jokes
    struct joke * jokes;
    struct nodeCat * next;
} nodeCat;

struct jokesCDT {
    nodeCat * first;
    size_t size; // Cant. de categorias.
};

jokesADT newJokes()
{
    calloc(1, sizeof(struct jokesCDT));
}

#define BLOCK   20
static char * copyStr(const char * s, size_t * dim)
{
    /* Copiamos de a bloques. */
    char * ans = NULL;

    /* IMPORTANTE: NO USAR STRLEN!! */
    size_t i;
    for (i = 0; s[i]; i++) {
        if (i % BLOCK == 0) {
            ans = realloc(ans, i + BLOCK);
        }
        ans[i] = s[i];
    }
    ans[i++] = 0;
    *dim = i; // incluye el 0.
    ans = realloc(ans, i);
    return ans;
}
static nodeCat * addCatRec(nodeCat * first,const char * category, int * flag)
{
    int cmp;
    if ( first == NULL || (cmp = strcmp(first->name, category)) > 0) {
        nodeCat * aux = malloc(sizeof(nodeCat));
        aux->name = copyStr(category, &(aux->len));
        aux->cant = 0;
        aux->jokes = NULL;
        aux->next = first;
        *flag = 1;
        return aux;
    }

    if (cmp == 0) 
        first->next = addCatRec(first->next, category, flag);

    return first;
}
void addCategory(jokesADT jokes, const char * category)
{
    int flag = 0;
    jokes->first = addCatRec(jokes->first, category, &flag);
}

static nodeCat * searchCat(nodeCat * first, const char * cat)
{
    
}

void addJoke(jokesADT jokes, const char * category, const char * joke) 
{
    nodeCat * aux = searchCat(jokes->first, category);
    if (aux == NULL) return;

    size_t cant = aux->cant;
    aux->jokes = realloc(aux->jokes, (cant+1) * sizeof(struct joke));
    aux->jokes[cant].text = copyStr(joke, &(aux->jokes[cant].len));
    aux->cant++;
}

static void freeJokes2(struct joke jokes[], size_t size) 
{
    for(size_t i = 0; i < size; i++) {
        free(jokes[i].text);
    }
    free(jokes);
}

static void freeCats(nodeCat * first)
{
    if (first == NULL) return;

    freeCats(first->next);
    free(first->name);
    freeJokes2(first->jokes, first->cant);
    free(first);
}
/* Liberar lista de categorias y de cada categoria el nombre. */
void freeJokes(jokesADT jokes)
{
    freeCats(jokes->first);
    free(jokes);
}
