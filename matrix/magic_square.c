#include <stdio.h>

#define ROWS 3
#define COLUMNS 3

int sum_diag2(int a[3][3]);
int sum_diag(int a[3][3]);
int sum_row(int a[3][3], int irow);
int sum_col(int a[3][3], int icol);

int main()
{
  int a[ROWS][COLUMNS];
  int diagSum = 0;
  int diagSum2 = 0;
  int row = 0, row2 = 0, row3 = 0, col = 0, col2 = 0, col3 = 0;
  int resArr[8];
  int total = 0;

  // чтение массива
  for (int i = 0; i < ROWS; i++)
  {
    // чтение одной строки a[i]
    for (int j = 0; j < COLUMNS; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }
  resArr[0] = sum_diag(a);
  resArr[1] = sum_diag2(a);
  resArr[2] = sum_row(a, 0);
  resArr[3] = sum_row(a, 1);
  resArr[4] = sum_row(a, 2);
  resArr[5] = sum_col(a, 0);
  resArr[6] = sum_col(a, 1);
  resArr[7] = sum_col(a, 2);

  for(int i=0;i<8;i++) {
    if(resArr[0] != resArr[i]) {
      total = 0;
      break;
    }else {
      total = 1;
    }
  }

  printf("%s\n", total ? "MAGIC" : "NO");
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

int sum_diag2(int a[3][3])
{
  int diagSum = 0;
  int colIdx = COLUMNS - 1;
  for (int i = 0; i < ROWS; i++)
  {
    diagSum += a[i][colIdx];
    colIdx--;
  }
  return diagSum;
}

int sum_row(int a[3][3], int irow)
{
  int rowSum = 0;
  for (int i = 0; i < ROWS; i++)
  {
    rowSum += a[irow][i];
  }
  return rowSum;
}
int sum_col(int a[3][3], int icol)
{
  int colSum = 0;
  for (int i = 0; i < ROWS; i++)
  {
    colSum += a[i][icol];
  }
  return colSum;
}
