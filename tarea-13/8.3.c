#include <stdio.h>

int main() {
    int num1 = 0, num2 = 1, siguiente, n;
    printf("Introduce el número hasta el que generar Fibonacci: ");
    scanf("%d", &n);

    printf("Serie Fibonacci: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", num1);
        siguiente = num1 + num2;
        num1 = num2;
        num2 = siguiente;
    }
    printf("\n");

    return 0;
}
