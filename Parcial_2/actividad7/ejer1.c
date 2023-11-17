#include <stdio.h>
#include <stdlib.h>

#define ALLOCATED_SIZE 64

int main() {
    int *ptr;

    for (int i = 0; i < ALLOCATED_SIZE; i++) {
        ptr = calloc(ALLOCATED_SIZE,sizeof(int));
        if (ptr == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        ptr[10] = 5000;
        printf("%X\n", ptr); // La razón de cambio es 16^2 o 256
    }
    free(ptr);
    printf("\nDIR: %X\n", ptr); // Imprime la última dirección de memoria usada, en este caso 34FBF00, pero varía.

    return 0;
}
