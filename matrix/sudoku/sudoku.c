#include <stdio.h>
#define N 9

// набиваю 1 цами idx -1 если есть
int checkRows(int sudoku[N][N])
{
  int isNotOk = 0;
  for (int i = 0; i < N; i++)
  {
    int checkValues[9] = {0};
    for (int j = 0; j < N; j++)
    {
      int val = sudoku[i][j];
      if (val < 1 || val > 9)
      {
        isNotOk = 1;
        break;
      }
      if (checkValues[val - 1] == 1)
      { // Дубликат!
        isNotOk = 1;
        break;
      }
      checkValues[val - 1] = 1;
    }
    if (isNotOk)
      break;
  }
  return isNotOk;
}

int checkColumns(int sudoku[N][N])
{
  int isNotOk = 0;
  for (int j = 0; j < N; j++)
  {
    int checkValues[9] = {0};
    for (int i = 0; i < N; i++)
    {
      int val = sudoku[i][j];
      if (val < 1 || val > 9)
      {
        isNotOk = 1;
        break;
      }
      if (checkValues[val - 1] == 1)
      {
        isNotOk = 1;
        break;
      }
      checkValues[val - 1] = 1;
    }
    if (isNotOk)
      break;
  }
  return isNotOk;
}

int checkSquare(int sudoku[N][N], int irow, int icol)
{
  int checkValues[N] = {0};
  int isNotOk = 0;
  for (int i = irow; i < irow + 3; i++)
  {
    for (int j = icol; j < icol + 3; j++)
    {
      int val = sudoku[i][j];

      if (val < 1 || val > N)
      {
        isNotOk = 1;
      }

      // if exists
      if (checkValues[val - 1] == 1)
      {
        isNotOk = 1;
      }

      checkValues[val - 1] = 1;
    }
  }
  return isNotOk;
}


//===================================================
int main()
{
  int isNotOk = 0;
    int sudoku[N][N];


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (scanf("%d", &sudoku[i][j]) != 1) {
                return 1; 
            }
        }
    }

    // 1. rows n cols
    isNotOk = checkRows(sudoku);
    if(isNotOk = 0) {
      isNotOk = checkColumns(sudoku);
    }

  //squares
    if (isNotOk == 0)
    {
        for (int i = 0; i < N; i += 3)
        {
            for (int j = 0; j < N; j += 3)
            {
                isNotOk = checkSquare(sudoku, i, j);
                if (isNotOk)
                {
                    break;
                }
            }
            if (isNotOk)
            {
                break;
            }
        }
    }

    printf("%s\n", isNotOk ? "NO" : "YES");
    return 0;
}