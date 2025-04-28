#include <stdio.h>
#include <ctype.h>

int contarPalabras(char* str) {
    int contador = 0, enPalabra = 0;
    while (*str != '\0') {
        if (isspace(*str)) {
            enPalabra = 0;  // Espacio, no estamos en una palabra
        } else if (enPalabra == 0) {
            enPalabra = 1;  // Empezamos una nueva palabra
            contador++;
        }
        str++;
    }
    return contador;
}

int main() {
    char cadena[100];
    printf("Introduce una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);

    // Eliminar salto de línea
    cadena[strcspn(cadena, "\n")] = '\0';

    int palabras = contarPalabras(cadena);
    printf("La cantidad de palabras es: %d\n", palabras);
    return 0;
}

