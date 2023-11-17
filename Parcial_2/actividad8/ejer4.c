#include <stdio.h>
#include <stdlib.h>
// I N T E G R A N T E S
// LEON CARLO RIVER CARDENAS
// DAVID HERNANDEZ CAMACHO

#define ROWS 3
#define COLS 4

void printmat(int **m,int rows,int cols);
void copy_matrix(int **copy_m, int **mat, int rows, int cols);

int main()
{
	int **mat;
	int ren,col;

	int totmem = 0;
	int memres;

	memres = ROWS * sizeof(int *);
	mat = malloc(memres);
	if(mat==NULL)
	{
		fprintf(stderr,"Error al solicitar memoria\n");
		exit(1);
	}
	totmem = totmem + memres;

	// Pedir memoria para cada renglón
	for(ren=0;ren<ROWS;ren++)
	{
		memres = COLS * sizeof(int);
		mat[ren] = malloc(memres);
		if(mat[ren]==NULL)
		{
			fprintf(stderr,"Error al solicitar memoria\n");
			exit(2);
		}
		totmem = totmem + memres;
	}

	// Inicializar los valores de la matriz
	for(ren=0;ren<ROWS;ren++)
		for(col=0;col<COLS;col++)
			mat[ren][col] = 10*(ren+1)+col+1;

	printmat(mat,ROWS,COLS);
	printf("\nMemoria solicitada al sistema %d bytes\n",totmem);

    //EJERCICIO 4
    int **copy_m;
    //Inicializar matriz copia
    copy_m = calloc(ROWS, sizeof(int *));
    for (int i = 0; i < ROWS; i++) {
        copy_m[i] = calloc(COLS, sizeof(int));
    }
    copy_matrix(copy_m, mat, ROWS, COLS);

    //Impresión matriz copia
    printf("Impresión de la matriz copia:\n");
    printmat(copy_m, ROWS, COLS);
    printf("\n");
}

void printmat(int **m,int rows,int cols)
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		printf("\n");
		for(j=0;j<cols;j++)
			printf("%d\t",m[i][j]);
	}
	printf("\n");
}

void copy_matrix(int **copy_m, int **mat, int rows, int cols){
    //Copiar contenido de matriz en "copy_m"
    printf("\n");
    for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
            copy_m[i][j] = mat[i][j];
        }
	}
}