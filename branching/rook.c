#include <stdio.h>

int main() {
  char xStart, xFin;
  int yStart, yFin;

  scanf("%c%d-%c%d", &xStart, &yStart, &xFin, &yFin);

  int res;
  if(xStart == xFin || yStart == yFin) {
    res = 1;
  }else {
    res = 0;
  }
  printf("%c%d-%c%d\n", xStart, yStart, xFin, yFin);
  printf("%s\n", res ? "YES" : "NO");
}