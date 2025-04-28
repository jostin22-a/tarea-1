#include <stdio.h>

void main(void) {
    int N, i, j;

    printf("Ingrese el tamaño de la matriz cuadrada (N): ");
    scanf("%d", &N);

    int matriz[N][N];

    // Llenar la matriz
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }

    // Imprimir la matriz
    printf("\nMatriz resultante:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}
