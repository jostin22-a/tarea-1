#include <stdio.h>
#include <ctype.h>  // Para usar tolower()

int contarVocales(char* str) {
    int contador = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]);  // Convertir a minúscula para simplificar comparación
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }
    return contador;
}

int main() {
    char cadena[100];
    printf("Introduce una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);

    // Eliminar salto de línea
    cadena[strcspn(cadena, "\n")] = '\0';

    int vocales = contarVocales(cadena);

    printf("El número de vocales en la cadena es: %d\n", vocales);
    return 0;
}

