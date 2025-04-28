#include <stdio.h>

void ordenarArreglo(int arreglo[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arreglo[j] > arreglo[j+1]) {
                int temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Introduce el número de elementos en el arreglo: ");
    scanf("%d", &n);

    int arreglo[n];
    printf("Introduce los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }

    ordenarArreglo(arreglo, n);

    printf("Arreglo ordenado en orden ascendente: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    return 0;
}

