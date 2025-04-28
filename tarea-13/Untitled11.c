#include <stdio.h>

int main() {
    int n;
    printf("Introduce el número de elementos en el arreglo: ");
    scanf("%d", &n);

    int arreglo[n];
    printf("Introduce los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }

    int max = arreglo[0];
    for (int i = 1; i < n; i++) {
        if (arreglo[i] > max) {
            max = arreglo[i];
        }
    }

    printf("El mayor número es: %d\n", max);
    return 0;
}

