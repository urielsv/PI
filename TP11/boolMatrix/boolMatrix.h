#ifndef BOLLMATRIX_BOOLMATRIX_H
#define BOLLMATRIX_BOOLMATRIX_H

// Matriz booleana infinita, por defecto todos en true
typedef struct boolMatrixCDT * boolMatrixADT;

boolMatrixADT newMatrix(void);
void freeBoolMatrix(boolMatrixADT m);
void setTrue(boolMatrixADT m, unsigned long row, unsigned long col);
void setFalse(boolMatrixADT m, unsigned long row, unsigned long col);
int get(const boolMatrixADT m, unsigned long row, unsigned long col);

#endif //BOLLMATRIX_BOOLMATRIX_H

