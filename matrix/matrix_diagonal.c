#include <stdio.h>

#define ROWS 3
#define COLUMNS 3

int sum_diag(int a[3][3]);


int main()
{
  int a[ROWS][COLUMNS];
  int sum = 0;

  // чтение массива
  for (int i = 0; i < ROWS; i++)
  {
    // чтение одной строки a[i]
    for (int j = 0; j < COLUMNS; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }

  sum = sum_diag(a);

  printf("%d\n", sum);
  return 0;
}

///===============
int sum_diag(int a[3][3])
{
  int diagSum = 0;
  for (int i = 0; i < ROWS; i++)
  {
    diagSum += a[i][i];
  }
  return diagSum;
}
