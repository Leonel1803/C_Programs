#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// I N T E G R A N T E S
// LEON CARLO RIVER CARDENAS
// DAVID HERNANDEZ CAMACHO

void multiplicar(int *am, int *bm, int *cm, int n){
    //Inicializar matriz
    srand(time(NULL));
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            *(am + i*n + j) = rand() % 11;
            *(bm + i*n + j) = rand() % 11;
        }
    }

    //Multiplicación
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            int mult_i = 0;
            for(int k = 0; k < n ; k++){
                mult_i += (*(am + i*n + k) * *(bm + k*n + j));
            }
            (*(cm + i*n + j)) = mult_i;
        }
    }
}

int main(){
    int n;
    printf("Dame el número de filas y renglones de tu matriz: ");
    scanf(" %d", &n);

    int *am, *bm, *cm;

    //Asignación de matrices
    am = calloc(n*n, sizeof(int));
    if(am == NULL)
    {
        fprintf(stderr, "No se pudo guardar la memoria");
        exit(1);
    }
    bm = calloc(n*n, sizeof(int));
    if(bm == NULL)
    {
        fprintf(stderr, "No se pudo guardar la memoria");
        exit(1);
    }
    cm = calloc(n*n, sizeof(int));
    if(cm == NULL)
    {
        fprintf(stderr, "No se pudo guardar la memoria");
        exit(1);
    }

    multiplicar(am, bm, cm, n);

    printf("A=\n");
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            printf("%d\t", *(am + i*n + j));
        }
        printf("\n");
    }
    printf("\n");

    printf("B=\n");
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            printf("%d\t", *(bm + i*n + j));
        }
        printf("\n");
    }
    printf("\n");

    printf("C=\n");
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            printf("%d\t", *(cm + i*n + j));
        }
        printf("\n");
    }
    printf("\n");

    free(am);
    free(bm);
    free(cm);

    return 0;
}