#include <stdio.h>

int main()
{
  int num, amount = 0;

  scanf("%d", &num);
  unsigned int c = 0;
  long long int d = 0;
  while ((c = getchar()) != EOF)
  {
    printf("Char: %d, is: %d\n", c, c-48==num);
    if(c>=48 && c<=57 && c-48 == num) {
      amount++;
    }
    d= d*10 + c;
    printf("%d %lld %d\n", num, d,amount);
  };

  printf("%d %lld %d\n", num, d, amount);

  return 0;
}