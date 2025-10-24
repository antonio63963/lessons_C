#include <stdio.h>
#define W 46  //.
#define B '*' // 42 // *
#define maxL 101

typedef struct
{
  int irow;
  int icol;
} Point;

typedef struct
{
  Point ltop;
  Point rbot;
  int amount;
} Rect;


Rect getRect(char field[maxL][maxL], int n, Point ltop)
{
  Rect rect = {.ltop = ltop};
  // check row
  for (int i = ltop.icol; i < n; i++)
  {

    if (field[ltop.irow][i] == B)
    {
      rect.rbot = (Point){.irow = ltop.irow, .icol = i};
    }
    else
    {
      break;
    }
  }
  for (int i = ltop.irow; i < n; i++)
  {
    if (field[i][ltop.icol] == B)
    {
      rect.rbot.irow = i;
    }
    else
    {
      break;
    }
  }
  int w = rect.rbot.icol - rect.ltop.icol +1;
  int h = rect.rbot.irow - rect.ltop.irow + 1;
  rect.amount = w * h;
  // printf("amount^^^ %d\n", rect.amount);
  return rect;
}

void getBigestRect(Rect allR[maxL], int n) {
  int big = 0;
  for(int i = 0; i<n; i++) {
    int size = allR[i].amount;
    if(size > big) {
      big = size;
    }
  }
  printf("%d\n", big);
}

void findRects(char field[maxL][maxL], int n) {
  Rect allR[maxL] = {0};
  int rIdx = 0;
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<n; j++) {
      if(field[i][j] == B) {
        //проверяю есть ли предыдущий B в строке и в колонке
        int isNotInLine = (j-1) >= 0 && field[i][j-1] != B || j ==0;
        int isNotInCollumn = (i-1) >= 0 && field[i-1][j] != B || i ==0;
        int isZerCol = j == 0 && i == 0 || j ==0 && isNotInCollumn;
        //printf("PREV LINE: %d, PREV COL: %d\n", isNotInLine, isNotInCollumn);

        if(isNotInLine == 1 && isNotInCollumn == 1 ) {
         // printf("IDX: %d, SIMBOL: %c\n", rIdx, field[i][j]);
          Point ltopRec = {.irow = i, .icol = j};
          Rect rect = getRect(field, n, ltopRec);
          // Нужно положить где-то rect
          allR[rIdx] = rect;
          rIdx++;
        } 
      }
    }
  }
  getBigestRect(allR, rIdx+1);
}

int main()
{
  int n;
  if (scanf("%d", &n) != 1)
    return 1;

  if (n > maxL - 1)
  {
    printf("Very big N...");
    return 1;
  }

  char field[maxL][maxL];
  for (int i = 0; i < n; i++)
  {
    scanf("%100s", field[i]);
  }

  findRects(field, n);

  return 0;
}
