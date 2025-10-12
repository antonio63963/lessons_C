#include <stdio.h>

#define R2 (5 * 5)

int main()
{
  int n;
  int x;
  int curretn= 0;
  int min = 0;

  scanf("%d", &n);

  for (int curretn = 0; curretn < n; curretn++)
  {
    if (1 == scanf("%d", &x))
    {
      if (min == 0 || x < min)
      {
        min = x;
      }
      printf("%d ", x);
    }
  }
  printf("\n%d\n", min);
  return 0;
}
