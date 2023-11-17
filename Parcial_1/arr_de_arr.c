#include <stdio.h>

int main(){
    int nums[] = {0 ,1 ,2 ,3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int *parr[] = {nums, nums+4, nums+8, nums+12};
    int r, c;

    printf("Dame la posición del renglón: "); scanf(" %d", &r);
    printf("Dame la posición de la columna: "); scanf(" %d", &c);

    printf("El dato es %d\n", parr[r][c]); //Se ve como una matriz, se accede al renglón inidcado (0-3) y ya que se accede a ese renglón que pertenece a un arreglo, se recorre c veces realtivo a lo especificado en el renglon 
    printf("El dato es %d\n", *(parr[r]+c));
    printf("El dato es %d\n", *(*(parr+r)+c));

    return 0;
}