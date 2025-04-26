#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "data.bin"

typedef struct {
    int id;
    char name[50];
    float value;
} Data;

void addData(Data **list, int *size);
void saveToFile(Data *list, int size);
void loadFromFile(Data **list, int *size);
void displayList(Data *list, int size);
void freeMemory(Data **list);

int main() {
    Data *list = NULL;
    int size = 0;
    int option;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Agregar estructura\n");
        printf("2. Guardar en archivo\n");
        printf("3. Cargar desde archivo\n");
        printf("4. Mostrar estructuras\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                addData(&list, &size);
                break;
            case 2:
                saveToFile(list, size);
                break;
            case 3:
                loadFromFile(&list, &size);
                break;
            case 4:
                displayList(list, size);
                break;
            case 5:
                printf("Saliendo...\n");
                freeMemory(&list);
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (option != 5);

    return 0;
}

void addData(Data **list, int *size) {
    *size += 1;
    *list = (Data *) realloc(*list, (*size) * sizeof(Data));
    if (*list == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    printf("Ingrese ID: ");
    scanf("%d", &((*list)[*size - 1].id));
    getchar();

    printf("Ingrese nombre: ");
    fgets((*list)[*size - 1].name, 50, stdin);
    (*list)[*size - 1].name[strcspn((*list)[*size - 1].name, "\n")] = 0;

    printf("Ingrese valor: ");
    scanf("%f", &((*list)[*size - 1].value));

    printf("Estructura agregada.\n");
}

void saveToFile(Data *list, int size) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    fwrite(&size, sizeof(int), 1, file);
    fwrite(list, sizeof(Data), size, file);
    fclose(file);
    printf("Datos guardados en el archivo.\n");
}

void loadFromFile(Data **list, int *size) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return;
    }

    fread(size, sizeof(int), 1, file);
    *list = (Data *) realloc(*list, (*size) * sizeof(Data));
    if (*list == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    fread(*list, sizeof(Data), *size, file);
    fclose(file);
    printf("Datos cargados desde el archivo.\n");
}

void displayList(Data *list, int size) {
    if (size == 0) {
        printf("No hay datos para mostrar.\n");
        return;
    }
    printf("\n--- Lista de estructuras ---\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Nombre: %s, Valor: %.2f\n", list[i].id, list[i].name, list[i].value);
    }
}

void freeMemory(Data **list) {
    free(*list);
    *list = NULL;
    printf("Memoria liberada.\n");
}

