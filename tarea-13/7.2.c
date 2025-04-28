#include <stdio.h>

void eliminarEspacios(char* str) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';  // A�adir el car�cter nulo al final
}

int main() {
    char cadena[100];
    printf("Introduce una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);

    // Eliminar salto de l�nea
    cadena[strcspn(cadena, "\n")] = '\0';

    eliminarEspacios(cadena);

    printf("Cadena sin espacios: %s\n", cadena);
����return�0;
}

