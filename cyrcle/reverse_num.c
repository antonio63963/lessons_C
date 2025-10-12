#include <stdio.h>

int main() {
  int num, revNum = 0, rest;

  scanf("%d", &num);

  do
  {
    rest = num % 10;
    revNum = revNum * 10 + rest;
    num /= 10;
    printf("num: %d, rev: %d, rest: %d\n", num, revNum, rest);
  } while (num != 0);

  printf("%d\n", revNum);
  
  return 0;
}