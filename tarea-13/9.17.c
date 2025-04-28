#include <stdio.h>

int esPerfecto(int num) {
    int suma = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            suma += i;
        }
    }
    return suma == num;
}

int main() {
    int limite;
    printf("Introduce el límite: ");
    scanf("%d", &limite);

    printf("Números perfectos hasta %d:\n", limite);
    for (int i = 2; i <= limite; i++) {
        if (esPerfecto(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

