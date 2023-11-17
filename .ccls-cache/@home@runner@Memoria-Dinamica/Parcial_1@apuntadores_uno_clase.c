#include <stdio.h>

int main(void) {
  
  int i, j, k;
  int *pi;

  pi = &i;
  *pi = 1;

  pi = &j;
  *pi = 6;

  pi = &k;
  *pi = 12;

  printf("i= %d, j= %d, k= %d", i, j, k);
  
  return 0;
}