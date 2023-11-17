#include <stdio.h>

int sumar(int a, int b) { return (a + b); }

int restar(int a, int b) { return (a - b); }

int multiplicar(int a, int b) { return (a * b); }

int main() {
  int (*funcarr[])(int, int) = {sumar, restar, multiplicar};
  int i;
  int res;

  for (i = 0; i < 3; i++) {
    res = funcarr[i](10, 20);
    printf("El resultado es %d\n", res);
  }
}