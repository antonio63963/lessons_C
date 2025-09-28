#include <stdio.h>

float foo(float x) {
  return x*x + 2*x + 3;
}

int main() {
  float z, a = 3;

  z= foo(a+2);

  printf("%f\n", z);
  
  return 0;
}