#include <stdio.h>


void sort2(int * a, int * b);

int main()
{
  int x, y;
  scanf("%d%d", &x, &y);
  sort2(&x, &y);
  printf("%d %d\n", x, y);
  return 0;
}

void sort2(int * a, int * b) {
    int a1 = *a;
    int b1 = *b;
    *a = a1 < b1 ? a1 : b1;
    *b = b1 > a1 ? b1 : a1;
}
