#include <stdio.h>

int main() {
    int num;
    printf("Introduce un n�mero: ");
    scanf("%d", &num);

    printf("Tabla de multiplicar de %d:\n", num);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

����return�0;
}
