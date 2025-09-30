#include <stdio.h>



int main() {
  char l, prewChar, nextChar;
  int row, prewRow, nextRow;

  scanf("%c%d", &l, &row);
  prewChar = l - 1;
  nextChar = l + 1;
  prewRow = row - 1;
  nextRow = row + 1;

  printf("%c%d %c%d %c%d %c%d", prewChar, row, l,nextRow, nextChar, row, l, prewRow);
  
  return 0;
}