
  // чтение массива
  for (int i = 0; i < ROWS; i++)
  {
    // чтение одной строки a[i]
    for (int j = 0; j < COLUMNS; j++)
    {
      scanf("%d", &a[i][j]);
    }
  }

  sum = sum_col(a, 1);

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