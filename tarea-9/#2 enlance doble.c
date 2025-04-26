/*Funciones básicas
Insertar al inicio*/
NodoDoble* insertarInicioDoble(NodoDoble* cabeza, int valor) {
    NodoDoble* nuevo = (NodoDoble*)malloc(sizeof(NodoDoble));
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = cabeza;

    if (cabeza != NULL)
        cabeza->anterior = nuevo;

    return nuevo;
}

