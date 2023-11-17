#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p1, *p2;
  int i;

  p1 = malloc(100 * sizeof(int));
  if (p1 == NULL) {
    fprintf(stderr, "Falló asignación de memoria\n");
    exit(1);
  }

  p2 = calloc(100, sizeof(int));
  if (p2 == NULL) {
    fprintf(stderr, "Falló asignación de memoria\n");
    exit(1);
  }

  printf("Contenido de los datos apuntados por p1\n");
  for (i = 0; i < 100; i++)
    printf("%d ", p1[i]);

  printf("Contenido de los datos apuntados por ps\n");
  for (i = 0; i < 100; i++)
    printf("%d ", p2[i]);

  free(p1);
  free(p2);

  return 0;
}