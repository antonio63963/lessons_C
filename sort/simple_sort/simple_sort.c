#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *p1, const void *p2)
{
  int x = *(const int *)p1;
  int y = *(const int *)p2;

  return (x > y) - (x < y);
}

void prInt(int *a, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main()
{
  int ar[10] = {2, 17, 22, -100, 0, -18, 77, -22, 3, 2};
  qsort(ar, 10, sizeof(int), cmp_int);

  prInt(ar, 10);
}