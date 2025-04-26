#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SUMA 1
#define RESTA 2
#define DIVISION 3
#define MULTIPLICACION 4
#define RAIZ_CUADRADA 5
#define POTENCIA_CUADRADA 6

#define ERR_OK 0
#define ERR_DbyZ 1
#define ERR_NEGATIVE_SQRT 2


void EntradaNumeros(float *n1, float *n2);
void EntradaUnNumero(float *n1);
int suma(float n1, float n2, float *pResult);
int resta(float n1, float n2, float *pResult);
int dividir(float n1, float n2, float *pResult);
int multiplicar(float n1, float n2, float *pResult);
int raiz_cuadrada(float n1, float *pResult);
int potencia_cuadrada(float n1, float *pResult);


float gResult = 0.0;

int main() {
    float numero1 = 0.0;
    float numero2 = 0.0;
    float result = 0.0;
    int menu = 0;
    int err = 0;

    do {
        printf("\n--- CALCULADORA ---");
        printf("\n0 - Salir");
        printf("\n1 - Suma");
        printf("\n2 - Resta");
        printf("\n3 - Divisi�n");
        printf("\n4 - Multiplicaci�n");
        printf("\n5 - Ra�z Cuadrada");
        printf("\n6 - Potenciaci�n al Cuadrado");
        printf("\nSeleccione una opci�n: ");
        scanf("%i", &menu);

        switch (menu) {
            case SUMA:
                EntradaNumeros(&numero1, &numero2);
                err = suma(numero1, numero2, &result);
                printf("\nLa suma de %.2f m�s %.2f es: %.2f\n", numero1, numero2, result);
                break;

            case RESTA:
                EntradaNumeros(&numero1, &numero2);
                err = resta(numero1, numero2, &result);
                printf("\nLa resta de %.2f menos %.2f es: %.2f\n", numero1, numero2, result);
                break;

            case DIVISION:
                EntradaNumeros(&numero1, &numero2);
                err = dividir(numero1, numero2, &result);
                if (err == ERR_DbyZ) {
                    printf("\nError: Divisi�n por 0 no permitida.\n");
                } else {
                    printf("\nLa divisi�n de %.2f entre %.2f es: %.2f\n", numero1, numero2, result);
                }
                break;

            case MULTIPLICACION:
                EntradaNumeros(&numero1, &numero2);
                err = multiplicar(numero1, numero2, &result);
                printf("\nLa multiplicaci�n de %.2f por %.2f es: %.2f\n", numero1, numero2, result);
                break;

            case RAIZ_CUADRADA:
                EntradaUnNumero(&numero1);
                err = raiz_cuadrada(numero1, &result);
                if (err == ERR_NEGATIVE_SQRT) {
                    printf("\nError: No se puede calcular la ra�z cuadrada de un n�mero negativo.\n");
                } else {
                    printf("\nLa ra�z cuadrada de %.2f es: %.2f\n", numero1, result);
                }
                break;

            case POTENCIA_CUADRADA:
                EntradaUnNumero(&numero1);
                err = potencia_cuadrada(numero1, &result);
                printf("\nEl cuadrado de %.2f es: %.2f\n", numero1, result);
                break;

            case 0:
                printf("\nFin del programa.\n");
                break;

            default:
                printf("\nOpci�n no v�lida. Intente de nuevo.\n");
                break;
        }

    } while (menu != 0);

    return 0;
}


void EntradaNumeros(float *n1, float *n2) {
    printf("\nIngrese n�mero 1: ");
    scanf("%f", n1);
    printf("Ingrese n�mero 2: ");
    scanf("%f", n2);
}


void EntradaUnNumero(float *n1) {
    printf("\nIngrese un n�mero: ");
    scanf("%f", n1);
}


int suma(float n1, float n2, float *pResult) {
    *pResult = n1 + n2;
    return ERR_OK;
}


int resta(float n1, float n2, float *pResult) {
    *pResult = n1 - n2;
    return ERR_OK;
}


int dividir(float n1, float n2, float *pResult) {
    if (n2 == 0.0) {
        return ERR_DbyZ;
    }
    *pResult = n1 / n2;
    return ERR_OK;
}


int multiplicar(float n1, float n2, float *pResult) {
    *pResult = n1 * n2;
    return ERR_OK;
}


int raiz_cuadrada(float n1, float *pResult) {
    if (n1 < 0) {
        return ERR_NEGATIVE_SQRT;
    }
    *pResult = sqrt(n1);
    return ERR_OK;
}


int potencia_cuadrada(float n1, float *pResult) {
    *pResult = pow(n1, 2);
    return ERR_OK;
}
