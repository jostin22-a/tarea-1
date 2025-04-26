/*Funciones básicas
Agregar un nodo al inicio*/
Nodo* insertarInicio(Nodo* cabeza, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = cabeza;
    return nuevo;
}

