/*Eliminar un nodo*/
Nodo* eliminarNodo(Nodo* cabeza, int valor) {
    Nodo* actual = cabeza;
    Nodo* anterior = NULL;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) return cabeza;

    if (anterior == NULL)
        cabeza = actual->siguiente;
    else
        anterior->siguiente = actual->siguiente;

    free(actual);
    return cabeza;
}

