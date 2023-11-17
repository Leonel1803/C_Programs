#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int **mat, rows, cols;

    printf("Give me the number of filas, loco: ");
    scanf("%d", &rows);
    printf("Now the number of columns, por favor: ");
    scanf("%d", &cols);
    printf("Tenkiu senpai (⁄ ⁄>⁄ ▽ ⁄<⁄ ⁄)\n");

    mat = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat[i] = calloc(cols, sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = (int) rand() % 100; //Add random number between 1 and 100
            printf("%2d\t", mat[i][j]);
        }
        printf("\n");
    }
    free(mat);
    return 0;
}