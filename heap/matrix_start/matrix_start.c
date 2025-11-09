#include <stdio.h>

int main()
{
  int a[3][4] = {
      {1, 2, 3, 4},
      {11, 12, 13, 14},
      {21, 22, 23, 24}};

  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 4; j++)
      printf("a[%d][%d] = %d at %p\n", i, j, a[i][j], &a[i][j]);

  return 0;
}