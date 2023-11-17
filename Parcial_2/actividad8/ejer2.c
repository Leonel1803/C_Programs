#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// I N T E G R A N T E S
// LEON CARLO RIVER CARDENAS
// DAVID HERNANDEZ CAMACHO

void multiplicar(int **am, int **bm, int **cm, int n){
    //Inicializar matriz
    srand(time(NULL));
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            am[i][j] = rand() % 11;
            bm[i][j] = rand() % 11;
        }
    }

    //Multiplicación
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            int mult_i = 0;
            for(int k = 0; k < n ; k++){
                mult_i += am[i][k]*bm[k][j];
            }
            cm[i][j] = mult_i;
        }
    }
}

int main(){
    int n;
    printf("Dame el número de filas y renglones de tu matriz: ");
    scanf(" %d", &n);

    int **am, **bm, **cm;

    //Asignación de matrices
    am = calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        am[i] = calloc(n, sizeof(int));
    }

    bm = calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        bm[i] = calloc(n, sizeof(int));
    }

    cm = calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        cm[i] = calloc(n, sizeof(int));
    }

    multiplicar(am, bm, cm, n);

    printf("A=\n");
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            printf("%d\t", am[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("B=\n");
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            printf("%d\t", bm[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("C=\n");
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            printf("%d\t", cm[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}