#include <stdio.h>

#define DEPARTAMENTOS 5
#define MESES 12

void main(void) {
    float ventas[DEPARTAMENTOS][MESES];
    float total_anual[DEPARTAMENTOS] = {0};
    float mayor_julio = 0;
    int depto_mayor_julio = 0;
    int mes_max_depto3 = 0, mes_min_depto3 = 0;

    // Ingreso de datos
    printf("Ingrese las ventas mensuales de cada departamento (5x12):\n");
    for (int i = 0; i < DEPARTAMENTOS; i++) {
        printf("Departamento %d:\n", i + 1);
        for (int j = 0; j < MESES; j++) {
            printf(" Mes %d: ", j + 1);
            scanf("%f", &ventas[i][j]);
        }
    }

    // Total anual por departamento y mayor venta en julio
    for (int i = 0; i < DEPARTAMENTOS; i++) {
        for (int j = 0; j < MESES; j++) {
            total_anual[i] += ventas[i][j];

            if (j == 6 && ventas[i][j] > mayor_julio) {  // Mes 7 = índice 6
                mayor_julio = ventas[i][j];
                depto_mayor_julio = i + 1;
            }
        }
    }

    // Buscar mes mayor y menor del depto 3 (índice 2)
    float max = ventas[2][0], min = ventas[2][0];
    for (int j = 1; j < MESES; j++) {
        if (ventas[2][j] > max) {
            max = ventas[2][j];
            mes_max_depto3 = j;
        }
        if (ventas[2][j] < min) {
            min = ventas[2][j];
            mes_min_depto3 = j;
        }
    }

    // Resultados
    printf("\n--- Resultados ---\n");
    for (int i = 0; i < DEPARTAMENTOS; i++) {
        printf("Total anual del Departamento %d: %.2f\n", i + 1, total_anual[i]);
    }
    printf("Mayor venta en julio: %.2f (Departamento %d)\n", mayor_julio, depto_mayor_julio);
    printf("Departamento 3 - Mes de mayor venta: %d\n", mes_max_depto3 + 1);
    printf("Departamento 3 - Mes de menor venta: %d\n", mes_min_depto3 + 1);
}

