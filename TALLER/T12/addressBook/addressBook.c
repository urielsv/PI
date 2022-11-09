#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "addressBook.h"

typedef struct person {
    tContact person;
    struct person * next;
} tPerson;

typedef struct group {
    char * name;
    tPerson * firstPerson;
    struct group * next;
} tGroup;

typedef struct addressBookCDT {
    tGroup * firstGroup;
    tGroup * currGroup;
    tPerson * currPerson;
} addressBookCDT;

static int
strcmpext(const char * a, const char * b) {
    int c = 0;
    while(*a && *b) {
        if((c = (tolower(*a) - tolower(*b))) != 0) {
            return c;
        }
        a++;
        b++;
    }
    return *a - *b;
}

addressBookADT newAddressBook()
{
    return calloc(1, sizeof(addressBookCDT));
}

static tGroup * addGroupRec(tGroup * first, const char * groupName, int * flag)
{
    int cmp;
    if (first == NULL || (cmp = strcmpext(first->name, groupName)) > 0) {
        tGroup * aux = malloc(sizeof(tGroup));
        aux->name = malloc(strlen(groupName+1));
        strcpy(aux->name, groupName);
        *flag = 1;
        aux->next = first;
        return aux;
    }

    if (cmp < 0)
        first->next = addGroupRec(first->next, groupName, flag);
    return first;
}

int addGroup(addressBookADT b, const char * groupName)
{
    int flag = 0;
    b->firstGroup = addGroupRec(b->firstGroup, groupName, &flag);
    return flag; 
}

/* Si existe groupName -> agregar contacto en book */
/* Si ya esta el contacto o no hay group no hace nada. */
static tGroup * hasGroupName(tGroup * first, const char * groupName)
{
    int cmp;
    if (first == NULL || (cmp = strcmpext(first->name, groupName)) > 0) {
        return NULL;
    }
    if (cmp == 0) {
        return first->next;
    }
    first->next = hasGroupName(first->next, groupName);
    return 1;
}

int addContact(addressBookADT b, const char * groupName, tContact contact)
{     
}

void toBeginForGroup(addressBookADT m, const char * groupName)
{
    int cmp;
    tGroup * aux = m->firstGroup;
    while (aux != NULL || (cmp = strcmpext(aux->name, groupName)) < 0) {
        aux = aux->next;
    }

}
