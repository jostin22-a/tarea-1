/*Recorrer la lista hacia adelante*/
void mostrarListaDoble(NodoDoble* cabeza) {
    NodoDoble* actual = cabeza;
    while (actual != NULL) {
        printf("%d <-> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

