#include <stdio.h>

// void inc(int * n) {
//   *n = (*n)++;
// }

typedef struct Point
{
  int x;
  int y;
} Point;

Point readPoint()
{
  Point res;
  scanf("%d%d", &res.x, &res.y);
  return res;
}

int main()
{
  // int a = 10;

  // inc(&a);

  // printf("%d\n", a);
  Point p = readPoint();
  printf("x: %d, y: %d\n", p.x, p.y);

  return 0;
}