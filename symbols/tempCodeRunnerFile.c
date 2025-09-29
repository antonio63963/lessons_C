#include <stdio.h>

int main() {
  char l; int n;

  scanf("%c%d", &l, &n);

  printf("%c%d\n", l, ++n);

  return 0;