#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INCREMENTO 5
#define MAX_CADENA 100

int main() {
    char **cadenas = NULL;
    int capacidad = INCREMENTO;
    int cantidad = 0;

    cadenas = (char **)malloc(capacidad * sizeof(char *));
    if (cadenas == NULL) {
        printf("Error al asignar memoria inicial.\n");
        return 1;
    }

    char buffer[MAX_CADENA + 1];

    while (1) {
        printf("Ingrese una cadena (o 'fin' para terminar): ");
        fgets(buffer, MAX_CADENA, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // eliminar salto de línea

        if (strcmp(buffer, "fin") == 0) {
            break;
        }

        if (cantidad == capacidad) {
            capacidad += INCREMENTO;
            char **temp = (char **)realloc(cadenas, capacidad * sizeof(char *));
            if (temp == NULL) {
                printf("Error al redimensionar memoria.\n");
                break;
            }
            cadenas = temp;
        }

        cadenas[cantidad] = (char *)malloc(strlen(buffer) + 1);
        if (cadenas[cantidad] == NULL) {
            printf("Error al asignar memoria para cadena.\n");
            break;
        }

        strcpy(cadenas[cantidad], buffer);
        cantidad++;
    }

    printf("\nCadenas ingresadas (en orden inverso):\n");
    for (int i = cantidad - 1; i >= 0; i--) {
        printf("%s\n", cadenas[i]);
    }

    for (int i = 0; i < cantidad; i++) {
        free(cadenas[i]);
    }
    free(cadenas);

    return 0;
}
