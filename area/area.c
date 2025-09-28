#include <stdio.h>
#include <math.h>

float dist(int x1, int y1, int x2, int y2)
{
  int a = x1 - x2;
  int b = y1 - y2;
  float c = sqrt(a * a + b * b);
  return c;
}

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{

  float b = dist(x1, y1, x3, y3);
  float c = dist(x1, y1, x2, y2);
  float a = dist(x3, y3, x2, y2);

  float p = (a + b + c) / 2;
  float square = sqrt(p * (p - a) * (p - b) * (p - c));
  return square;
}

int main()
{
  int x1, y1, x2, y2, x3, y3;

  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);

  float s = area(x1, y1, x2, y2, x3, y3);
  printf("%.3f\n", s);

  return 0;
};
