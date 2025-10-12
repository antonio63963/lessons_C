#include <stdio.h>

int main()
{
  int num, revNum = 0, rest;

  scanf("%d", &num);
  int srcnum = num;

  do
  {
    rest = num % 10;
    revNum = revNum * 10 + rest;
    num /= 10;
    printf("num: %d, rev: %d, rest: %d\n", num, revNum, rest);
  } while (num != 0);

  printf("%s\n", revNum == srcnum ? "YES" : "NO");

  return 0;
}