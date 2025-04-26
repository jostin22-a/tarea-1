/*Ejemplo de uso*/
int main() {
    Nodo* cabeza = NULL;

    cabeza = insertarInicio(cabeza, 10);
    cabeza = insertarInicio(cabeza, 20);
    cabeza = insertarInicio(cabeza, 30);

    printf("Lista: ");
    mostrarLista(cabeza);

    cabeza = eliminarNodo(cabeza, 20);
    printf("Después de eliminar 20: ");
    mostrarLista(cabeza);

    return 0;
}

