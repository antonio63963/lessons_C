#include <stdio.h>

void inc(int * n) {
  *n = ++(*n);
}

int main() {
  int a = 10;

  inc(&a);

  printf("%d\n", a);
  
  return 0;
}