#include <stdio.h>

void rec_print(int from, int to);

int main(void)
{
  int a, b;
  scanf("%d%d", &a, &b);

  rec_print(a, b);

  return 0;
}

void rec_print(int from, int to)
{
  if (from <= to)
  {
    printf("%d ", from);
    rec_print(from + 1, to);
  }
  else
  {

    return;
  }
}