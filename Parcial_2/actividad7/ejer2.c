#include <stdio.h>
#include <stdlib.h>

int main() {
    int *elements, n, sum = 0;
    float average;

    printf("Indique el número de elementos: ");
    scanf("%d", &n);
    elements = calloc(n, sizeof(int));
    if (elements == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("Insert number %d: ", i+1);
        scanf("%d", &elements[i]);
        sum += elements[i];
    }

    average = (float) sum / n;
    printf("\nThe average is: %f\n\n", average);

    printf("Total memory used: %d bytes", sizeof(elements)*n);
    free(elements); // Freeing space of dynamically allocated memory
    return 0;
}