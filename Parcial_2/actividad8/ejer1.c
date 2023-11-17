#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// I N T E G R A N T E S
// LEON CARLO RIVER CARDENAS
// DAVID HERNANDEZ CAMACHO


#define lower 2
#define upper 20

int main(void) {
	srand(time(NULL));
	int r = 0,ROWS = 0,f = 0;

	printf("Cuantos renglones tiene? ");
	scanf("%d",&ROWS);
    int **mat;
    mat = calloc(ROWS,sizeof(int *));

    if(mat == NULL)
    {
        fprintf(stderr,"No se pudo alocar la memoria");
        exit(0);
    }

	for(int i=0;i<ROWS;i++)
	{
        r = (rand() % (lower-upper + 1)) + lower;

        if(0<=f<ROWS)
        {
            f++;
        }
        else
        {
            break;
        }
        mat[i] = calloc(f,sizeof(int *));

		for(int j=0;j<f;j++)
		{

			mat[i][f] = r;

			printf("%d\t",mat[i][f]);
		}


		printf("\n");
	}


	return 0;
}
