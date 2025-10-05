#include <stdio.h>

int main()
{
  int a1, a2, b1, b2;
  scanf("%d:%d", &a1, &b1);
  scanf("%d:%d", &a2, &b2);

  int a = a1 + a2;
  int b = b1 + b2;

  int bonus = 0;
  if (a > b)
  {
    bonus += 2;
  }
  else if (a == b)
  {
    bonus += 1;
  }

  printf("%d:%d\n", a, b);
  printf("%d\n", bonus);
  return 0;
}
