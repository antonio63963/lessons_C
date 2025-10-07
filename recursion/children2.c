#include <stdio.h>
#include <math.h>

int delim_konfety(int a);
int delim(int a, int *ch);

int main()
{
  int konfet;
  scanf("%d", &konfet);

  int detey = delim_konfety(konfet);
  printf("%d\n", detey);

  return 0;
}

int delim_konfety(int a)
{
  int ch = 0;
  delim(a, &ch);
  return ch;
}

int delim(int a, int *ch)
{
  if (a > 0)
  {
    int rest = a - (a / 2);
    *ch = *ch + 1;
    if (a > 1)
      delim(rest, ch);
  }
}