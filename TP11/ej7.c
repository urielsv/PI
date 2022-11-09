/* Funcion map para modificar los elementos de la lista. */

typedef elemType (*fn)(elemType n);

void map(listADT myList, fn(elemType n))
{
    /* 
     * Empiezo la sub en el primero y mientras que no se haya terminado aplico
     * la funcion especificada a cada head de nodo.
     */

    TList aux = list->first;
    while ( aux != NULL) {
        aux->first = fn(aux->head);
        aux = aux->tail;
    }
}
