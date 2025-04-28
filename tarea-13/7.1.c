#include <stdio.h>
#include <string.h>

int main() {
    char cadena1[50], cadena2[50];

    // Pedir al usuario que ingrese dos cadenas
    printf("Introduce la primera cadena: ");
    fgets(cadena1, sizeof(cadena1), stdin);  // Usar fgets para leer cadenas con espacios

    printf("Introduce la segunda cadena: ");
    fgets(cadena2, sizeof(cadena2), stdin);

    // Eliminar el salto de línea al final de las cadenas leídas con fgets
    cadena1[strcspn(cadena1, "\n")] = '\0';
    cadena2[strcspn(cadena2, "\n")] = '\0';

    // Mostrar las cadenas
    printf("La primera cadena es: %s\n", cadena1);
    printf("La segunda cadena es: %s\n", cadena2);

    // Comparar las cadenas
    if (strcmp(cadena1, cadena2) == 0) {
        printf("Las cadenas son iguales.\n");
    } else {
        printf("Las cadenas son diferentes.\n");
    }

    // Concatenar las cadenas
    strcat(cadena1, cadena2);
    printf("La concatenación de las cadenas es: %s\n", cadena1);

    // Longitud de la cadena resultante
    printf("La longitud de la cadena concatenada es: %zu\n", strlen(cadena1));

    return 0;
}

