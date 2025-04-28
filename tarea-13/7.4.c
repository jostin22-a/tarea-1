#include <stdio.h>

void copiarCadena(char* origen, char* destino) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';  // Asegurar el carácter nulo al final
}

int main() {
    char cadena1[100], cadena2[100];
    printf("Introduce la primera cadena: ");
    fgets(cadena1, sizeof(cadena1), stdin);

    // Eliminar salto de línea
    cadena1[strcspn(cadena1, "\n")] = '\0';

    copiarCadena(cadena1, cadena2);

    printf("La cadena copiada es: %s\n", cadena2);
    return 0;
}

