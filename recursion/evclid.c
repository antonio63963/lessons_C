#include <stdio.h>

int getNode(int a, int b);

int main()
{
  int a, b;

  scanf("%d%d", &a, &b);
  
  int res = getNode(a, b);

  printf("%d\n", res);

  return 0;
}

int getNode(int a, int b)
{
  int max = a > b ? a : b;
  int min = a < b ? a : b;
  if (min == 0)
  {
    return max;
  }
  else
  {
    int rest = max % min;
    getNode(min, rest);
  }
}