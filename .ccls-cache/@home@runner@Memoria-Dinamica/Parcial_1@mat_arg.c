#include <stdio.h>

void printmat1(int mat_a[4][4]);
void printmat2(int mat_a[][4], int rows);
void printmat3(void *mat_a, int rows, int cols);
void printmat4(void *mat_a, int rows, int cols);
void printmat5(int *mat_a, int rows, int cols);

int main() {
  int mat_a[4][4] = {
      {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};
  printmat1(mat_a);
  printmat2(mat_a, 4);
  printmat3(mat_a, 4, 4);
  printmat4(mat_a, 4, 4);
  printmat5((int *)mat_a, 4, 4);

  return 0;
}

void printmat1(int mat_a[4][4]) { // Esta función solo podría procesar un
                                  // arreglo de 3 filas y 3 columnas
  printf("\nPrimera función: \n");
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      printf("%d\t", mat_a[i][j]);
    }
    printf("\n");
  }
}

void printmat2(int mat_a[][4],
               int rows) { // Esta funcion puede procesar un arreglo de filas
                           // indefinidas y de 3 columnas
  printf("\nSegunda función: \n");
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < 4; j++) {
      printf("%d\t", mat_a[i][j]);
    }
    printf("\n");
  }
}

void printmat3(void *mat_a, int rows,
               int cols) { // Esta funcion puede procesar un arreglo de filas y
                           // columnas indefinidas; gracias a los apuntadores.
                           // Con apuntador void, no se necesita hacer un cast
  printf("\nTercera función: \n");
  int i, j;
  int *arrum;
  arrum = mat_a;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d\t", *arrum);
      arrum++;
    }
    printf("\n");
  }
}

void printmat4(void *mat_a, int rows,
               int cols) { // Esta funcion puede procesar un arreglo de filas y
                           // columnas indefinidas; gracias a los apuntadores.
                           // Con apuntador void, no se necesita hacer un cast
  printf("\nCuarta función: \n");
  int i, j;
  int *arrum;
  arrum = mat_a;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d\t", *(arrum + i * cols + j));
    }
    printf("\n");
  }
}

void printmat5(int *mat_a, int rows,
               int cols) { // Esta funcion puede procesar un arreglo de filas y
                           // columnas indefinidas; gracias a los apuntadores.En
                           // esta se hace un cast con el tipo de dato int
  printf("\nQuinta función: \n");
  int i, j;
  int *arrum;
  arrum = mat_a;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      printf("%d\t", *(arrum + i * cols + j));
    }
    printf("\n");
  }
}