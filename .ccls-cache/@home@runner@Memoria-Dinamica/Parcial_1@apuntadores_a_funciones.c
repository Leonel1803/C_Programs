#include <math.h>
#include <stdio.h>

int sumar(int a, int b) { return (a + b); }

int restar(int a, int b) { return (a - b); }

int multiplicar(int a, int b) { return (a * b); }

int dividir(int a, int b) { return (a / b); }

int main() {
  int (*ptrfunc)(int, int);
  int a = 10, b = 20, c;

  ptrfunc = sumar;
  c = ptrfunc(a, b);
  printf("El valor de c es %d\n", c);

  ptrfunc = restar;
  c = ptrfunc(a, b);
  printf("El valor de c es %d\n", c);

  ptrfunc = multiplicar;
  c = ptrfunc(a, b);
  printf("El valor de c es %d\n", c);

  ptrfunc = dividir;
  c = ptrfunc(a, b);
  printf("El valor de c es %d\n", c);

  return 0;
}