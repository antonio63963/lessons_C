#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *p1, const void *p2)
{
  int a = *(int *)p1;
  int b = *(int *)p2;

  if (a > b)
  {
    return 1;
  }
  else if (a < b)
  {
    return -1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  int n;

  scanf("%d", &n);
  int arr[n];

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  qsort(arr, n, sizeof(arr[0]), cmp_int);

  for (int i = 0; i < n; i++)
  {
    printf("%d\n", arr[i]);
  }

  return 0;
}