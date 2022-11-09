#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "social.h"

#define MAXSIZE 21


struct related {
    char name[MAXSIZE];
    struct related * next;
};

typedef struct person {
    char name[MAXSIZE];
    struct related * first;
    size_t relCtr; // Contador de relacionados.
    struct person * next;
} TPerson;

typedef TPerson * TPeople;
typedef struct related * TRelated;

struct socialCDT {
    TPerson * people;
    size_t ctr;
};

socialADT newSocial()
{
    return calloc(1, sizeof(TPerson));
}

static TPeople addPersonRec(TPeople first, const char * thisName, int * flag) {
    int cmp;
    if (first == NULL || (cmp = strcmp(first->name, thisName)) > 0) {
        TPeople aux = malloc(sizeof(TPeople));
        aux->first = NULL;
        aux->relCtr = 0;
        strncpy(aux->name, thisName, MAXSIZE-1);
        aux->name[MAXSIZE-1] = '\0';
        aux->next = first;
        *flag = 1;
        return aux;
    }
    if (cmp < 0)
        first->next = addPersonRec(first->next, thisName, flag);
    return first;
}

void addPerson(socialADT soc, const char * name)
{
    int flag = 0;
    soc->people = addPersonRec(soc->people, name, &flag);

    if (flag)
        soc->ctr++;
}
static TRelated addRelatedRec(TRelated first, const char * thisName)
{
    int cmp;
    if (first == NULL || (cmp = strcmp(first->name, thisName)) > 0) {
    TRelated aux = malloc(sizeof(TRelated));
    strncpy(aux->name, thisName, MAXSIZE-1);
    aux->name[MAXSIZE-1] = '\0';
    aux->next = first;
    return aux;
    }

    if (cmp < 0) 
        first->next = addRelatedRec(first->next, thisName);
    
    return first;
}

static TPeople findPerson(TPeople first, const char * thisName) 
{
    TPeople aux = first;
    while ( aux != NULL) {
        int cmp = strcmp(aux->name, thisName);
        if (cmp == 0) 
            return aux;
        if (cmp > 0)
            return NULL;
        aux = aux->next;
    }
    return NULL;

}

void addRelated(socialADT soc, const char * name, const char * related)
{
    TPeople aux = findPerson(soc->people, name);
    /* Solo agrega si la persona existe. */
    if ( aux != NULL) {
        /* Agrega la relacion y guarda una copia de related. */
        aux->first = addRelatedRec(aux->first, related);
        aux->relCtr++;
    }
}

static char * cpyStrHeap(const char * s) {
    return strcpy(malloc(strlen(s)+1), s);
}

char ** related(const socialADT soc, const char * person)
{
    char ** ans;
    TPeople per = findPerson(soc->people, person);
    
    int ctr = 0;
    /* Si hay persona entonces la guardo en el vector dinamico de respuestas. */
    if (per != NULL) {
        /* Tam: tipo * cantidad de relaciones + 1. */
        ans = malloc(sizeof(char *) * (per->relCtr+1));
        TRelated aux = per->first;

        /* Recorro la lista hasta el final y copio los nombres de las
         * relaciones. */
        while (aux != NULL) {
            ans[ctr++] = cpyStrHeap(aux->name);
            aux = aux->next;
        }
    } else {
        ans = malloc(sizeof(char *));
    }
    ans[ctr] = NULL;
    return ans;
}

char ** persons(const socialADT soc)
{
    char ** ans = malloc(sizeof(char *) * (soc->ctr + 1));

    TPeople aux = soc->people;
    
    int ctr = 0;
    while (aux != NULL) {
        ans[ctr++] = cpyStrHeap(aux->name);
        aux = aux->next;
    }

    ans[ctr] = NULL;
    return ans;
}
