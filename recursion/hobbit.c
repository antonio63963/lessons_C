#include <stdio.h>

void rec_print(int from, int to);
void rec_print_rev(int from, int to);

int main(void)
{
  int a, b;
  scanf("%d%d", &a, &b);

  rec_print(a, b);
  rec_print_rev(b, a);

  return 0;
}

void rec_print(int from, int to)
{

  if (from < to)
  {
    printf("%d ", from);
    rec_print(from + 1, to);
  }
  else if (from == to)
  {
    printf("%d\n", from);
    rec_print(from + 1, to);
  }

  else
  {
    return;
  }
}

void rec_print_rev(int from, int to)
{
  if (from < to)
  {
    return;
  }
  if (from >= to)
  {
    printf("%d ", from);
    rec_print_rev(from - 1, to);
  }
}