/*Eliminar un nodo*/
NodoDoble* eliminarNodoDoble(NodoDoble* cabeza, int valor) {
    NodoDoble* actual = cabeza;

    while (actual != NULL && actual->dato != valor)
        actual = actual->siguiente;

    if (actual == NULL) return cabeza;

    if (actual->anterior != NULL)
        actual->anterior->siguiente = actual->siguiente;
    else
        cabeza = actual->siguiente;

    if (actual->siguiente != NULL)
        actual->siguiente->anterior = actual->anterior;

    free(actual);
    return cabeza;
}

