#include <stdio.h>

#define ROWS 3
#define COLUMNS 3

int sum_col(int a[3][3], int icol);
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

  sum = sum_col(a, 2);

  printf("%d\n", sum);
  return 0;
}

///===============
int sum_col(int a[3][3], int icol)
{
  int colSum = 0;
  for (int i = 0; i < ROWS; i++)
  {
    colSum += a[i][icol];
    //printf("sum on %d, sum: %d\n", i, colSum);
  }
  return colSum;
}
