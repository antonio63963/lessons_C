#include <stdio.h>

void rotateC(int *x1, int *y1, int *x2, int *y2)
{
  int centreX = (*x1 + *x2) / 2;
  int centerY = (*y1 + *y2) / 2;

  int width = *x2 - *x1;
  int height = *y1 - *y2;

  int xFin1 = centreX - height / 2;
  int yFin1 = centerY + width / 2;

  int xFin2 = centreX + height / 2;
  int yFIn2 = centerY - width / 2;

  printf("%d %d %d %d\n", xFin1, yFin1, xFin2, yFIn2);
};

int main()
{
  int xlt, ylt, xrb, yrb;
  int *xl = &xlt;
  int *yl = &ylt;
  int *xr = &xrb;
  int *yr = &yrb;

  scanf("%d%d%d%d", xl, yl, xr, yr);

  rotateC(xl, yl, xr, yr);
};
