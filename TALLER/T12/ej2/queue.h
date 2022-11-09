
typedef struct queueCDT * queueADT;
typedef int elemType;

// Crear la colita.
queueADT newQueue();
// Encolar un elemento.
void addQueue(queueADT q, elemType elem);
// Desencolar un elemento.
void dequeue(queueADT q, elemType * elem);
// Fijarse si las cola esta vacia.
int isEmpty(queueADT q);
// Liberar la cola.
void freeQueue(queueADT q);
