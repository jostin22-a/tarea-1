#include <stdio.h>

int esPrimo(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int limite;
    printf("Introduce el número límite: ");
    scanf("%d", &limite);

    printf("Números primos hasta %d:\n", limite);
    for (int i = 2; i <= limite; i++) {
        if (esPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

