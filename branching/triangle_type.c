#include <stdio.h>

int triangle_len_type(int a, int b, int c)
{
  int res;
  int isTriangle = a+b > c  && b+c > a && a+c > b;
  if (!isTriangle || (a <= 0 || b <= 0 || c <= 0))
  {
    res = -1;
    return res;
  }
  if (a == b && b == c)
  {
    res = 2;
  }
  else if (a == b || a == c || b == c)
  {
    res = 1;
  }
  else if (a != b && b != c)
  {
    res = 0;
  }
  else
  {
    res = -1;
  }
  return res;
};

int main()
{
  int a, b, c;

  scanf("%d%d%d", &a, &b, &c);

  int res = triangle_len_type(a, b, c);

  printf("%d\n", res);

  return 0;
}