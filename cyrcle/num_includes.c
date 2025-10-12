#include <stdio.h>

int main() {
  int src, num, d, amount = 0, rest;

  scanf("%d%d", &d, &num);
src = num;
  do
  {
    rest = num % 10;
    // revNum = revNum * 10 + rest;
    if(rest == d) {
      amount++;
    }
    num /= 10;
  } while (num != 0);

  printf("%d %d %d\n", d, src, amount);
  
  return 0;
}