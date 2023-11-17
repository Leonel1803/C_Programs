#include <stdio.h>

int main() {
    int a[3][3], b[3][3], c[3][3], i, j, k;
    FILE *fa, *fb, *fc;

    // Abrir archivos de entrada y salida
    fa = fopen("a.txt", "r");
    fb = fopen("b.txt", "r");
    fc = fopen("c.txt", "w");

    // Leer la matriz a desde el archivo a.txt
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            fscanf(fa, "%d", &a[i][j]);
        }
    }

    // Leer la matriz b desde el archivo b.txt
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            fscanf(fb, "%d", &b[i][j]);
        }
    }

    // Multiplicar las matrices a y b
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            c[i][j] = 0;
            for (k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Escribir la matriz resultante en el archivo c.txt
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            fprintf(fc, "%d ", c[i][j]);
        }
        fprintf(fc, "\n");
    }

    // Cerrar archivos
    fclose(fa);
    fclose(fb);
    fclose(fc);

    printf("Multiplicación de matrices completada.\n");

    return 0;
}
