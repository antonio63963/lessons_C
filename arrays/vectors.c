#include <stdio.h>

int main()
{
  int n, i;
  scanf("%d", &n);
  int a[n];
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  int b[n];
  for (i = 0; i < n; i++)
  {
    scanf("%d", &b[i]);
  }
  // int sum[n];
  int sclar = 0;
  for (i = 0; i < n; i++)
  {
    scalar += (a[i] * b[i]);
  }
  printf("%d\n", sclar);

  return 0;
}