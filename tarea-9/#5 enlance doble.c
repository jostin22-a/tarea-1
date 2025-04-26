/*Ejemplo de uso*/
int main() {
    NodoDoble* cabeza = NULL;

    cabeza = insertarInicioDoble(cabeza, 10);
    cabeza = insertarInicioDoble(cabeza, 20);
    cabeza = insertarInicioDoble(cabeza, 30);

    printf("Lista doblemente enlazada: ");
    mostrarListaDoble(cabeza);

    cabeza = eliminarNodoDoble(cabeza, 20);
    printf("Después de eliminar 20: ");
    mostrarListaDoble(cabeza);

    return 0;
}


