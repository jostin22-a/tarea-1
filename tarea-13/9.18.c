#include <stdio.h>

int main() {
    int n;
    printf("Introduce el n�mero de elementos en el arreglo: ");
    scanf("%d", &n);

    int arreglo[n];
    printf("Introduce los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arreglo[i]);
    }

    int impares = 0;
    for (int i = 0; i < n; i++) {
        if (arreglo[i] % 2 != 0) {
            impares++;
        }
    }

    printf("Cantidad de n�meros impares: %d\n", impares);
����return�0;
}

