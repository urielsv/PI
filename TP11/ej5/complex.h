typedef struct complexCDT * complexADT;

complexADT newComp(float real, float imag);
float getRealComp(complexADT comp);
float getImagComp(complexADT comp);
complexADT sumComp(complexADT c1, complexADT c2);
void freeComp(complexADT comp);


