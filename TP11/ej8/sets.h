
#ifndef SETS__H_
#define SETS__H_

typedef struct setsCDT * setsADT;
typedef int elemType;

setsADT newSet();
void addElem(setsADT set, elemType elem);
void remElem(setsADT set, elemType elem);
setsADT union(setsADT s1, setsADT s2);
setsADT inter(setsADT s1, setsADT s2);
setsADT substr(setsADT s1, setsADT s2);

