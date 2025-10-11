#include <stdio.h>

int main()
{
  int l, k, s, days = 1;

  int i = 0;
  int donekm = 0;

  scanf("%d\n%d\n%d", &l, &k, &s);
  donekm = l;
  while (donekm < s)
  {
    i+=k;
    donekm +=  l + i;
    days += 1;
    printf("donekm: %d, days: %d\n", donekm, days);
  }

  printf("%d\n", days);
}