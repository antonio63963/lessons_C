#include <stdio.h>

int isGoodDivide(int num)
{
  int res;
  if (num % 3 == 0 && num % 15 != 0)
  {
    res = 1;
  }
  else if (num % 5 == 0 && num % 15 != 0)
  {
    res = 1;
  }
  else
  {
    res = 0;
  }
  return res;
}

int main() {
  int num;

  scanf("%d", &num);

  printf("%s\n", isGoodDivide(num) ? "YES" : "NO");

  return 0;
}