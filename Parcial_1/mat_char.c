#include <stdio.h>

void printcads(void *p, int cads, int len) {
  int i;
  char *s = p;

  for (i = 0; i < cads; i++) {
    printf("%s\n", s);
    s += len;
  }
  printf("\n");
}

int main() {
  char mat1[][5] = {"UNO", "DOS", "TRES"};
  char mat2[][5] = {
      {'U', 'N', 'O', 0, 0}, {'D', 'O', 'S', 0, 0}, {'T', 'R', 'E', 'S', 0}};
  char mat3[] = "UNO\0\0DOS\0\0TRES\0";
  char mat4[] = {'U', 'N', 'O', 0,   0,   'D', 'O', 'S',
                 0,   0,   'T', 'R', 'E', 'S', 0};
  // Todos estos arreglos son equivalentes

  printcads(mat1, 3, 5);
  printcads(mat2, 3, 5);
  printcads(mat3, 3, 5);
  printcads(mat4, 3, 5);

  return 0;
}