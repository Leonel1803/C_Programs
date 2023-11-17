#include <stdio.h>
#include <stdlib.h>

int lenght(char string[]) {
  char *astring = string;
  int cont = 0;
  while (*astring != '\0') {
    astring++;
    cont += 1;
  }
  return cont;
}

int main() {
  char string[] = "Hola Mundo";
  printf("La medida del arreglo \"%s\" es %d\n\n", string, lenght(string));

  system("pause");
  return 0;
}