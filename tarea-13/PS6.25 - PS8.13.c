#include <stdio.h>
#include <math.h>

#define N 8

int tablero[N], soluciones = 0;

// Función para verificar si la reina se puede colocar
int es_seguro(int fila, int col) {
    for (int i = 0; i < fila; i++) {
        if (tablero[i] == col || abs(tablero[i] - col) == abs(i - fila))
            return 0; // Mismo columna o misma diagonal
    }
    return 1;
}

// Backtracking recursivo
void resolver(int fila) {
    if (fila == N) {
        soluciones++;
        printf("\nSolución %d:\n", soluciones);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (tablero[i] == j)
                    printf(" Q ");
                else
                    printf(" . ");
            }
            printf("\n");
        }
    } else {
        for (int col = 0; col < N; col++) {
            if (es_seguro(fila, col)) {
                tablero[fila] = col;
                resolver(fila + 1);
            }
        }
    }
}

void main(void) {
    printf("Resolviendo el problema de las 8 reinas...\n");
    resolver(0);
    printf("\nTotal de soluciones: %d\n", soluciones);
}

