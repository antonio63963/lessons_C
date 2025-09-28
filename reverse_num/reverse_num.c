#include <stdio.h>

void print_revers(int x)
{
  int x1, x2, x3, x4, x5, x6;

  x6 = x / 100000;
  int x6Rest = x % 100000;
  x5 = x6Rest / 10000;
  int x5Rest = x6Rest % 10000;
  x4 = x5Rest / 1000;
  int x4Rest = x5Rest % 1000;
  x3 = x4Rest / 100;
  int x3Rest = x4Rest % 100;
  x2 = x3Rest / 10;
  x1 = x3Rest % 10;

  printf("%d%d%d%d%d%d\n", x1, x2, x3, x4, x5, x6);
};

int main()
{
  int x = 123456;
  print_revers(x);
  return 0;
}
