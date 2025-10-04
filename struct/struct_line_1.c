#include <stdio.h>
#include <math.h>

typedef struct
{
  int x;
  int y;
} Point;

typedef struct
{
  Point a;   // начало отрезка
  Point b;   // конец отрезка
  float len; // длина отрезка
} Line;

float distance(Point a, Point b); // расстояние между точками
void scanLine(Line *t);
void printLine(Line t);
void rotRLine(Line *t);

int main()
{
  Line t;

  scanLine(&t);
  rotRLine(&t);
  printLine(t);

  return 0;
}

float distance(Point a, Point b)
{
  float length;
  if (a.x == b.x)
  {
    length = a.y - b.y;
  }
  else if (a.y == b.y)
  {
    length = a.x - b.x;
  }
  else
  {
    int a2 = a.x - b.x;
    int b2 = a.y - b.y;
    length = sqrt(a2 * a2 + b2 * b2);
  }
  return fabsf(length);
}

void scanLine(Line *t)
{
  scanf("%d%d%d%d", &t->a.x, &t->a.y, &t->b.x, &t->b.y);
}

void printLine(Line t)
{
  printf("%d %d %d %d %.3f\n", t.a.x, t.a.y, t.b.x, t.b.y, t.len);
}

void rotRLine(Line *t)
{
  // Line line = *t;
  float dis = distance(t->a, t->b);
  int axR = t->a.y;
  int ayR = t->a.x * -1;
  int bxR = t->b.y;
  int byR = t->b.x * -1;
  *t = (Line){.a = {.x = axR, .y = ayR}, .b = {.x = bxR, .y = byR}, .len = dis};
}
