#include <stdio.h>

struct Point
{
  int x;
  int y;
};
struct Rect
{
  struct Point lt; // левая верхняя вершина
  struct Point rb; // правая нижняя вершина
};

int is_crossed(struct Rect a, struct Rect b);

int main()
{
  struct Rect a = {.lt = {-7, 8}, .rb = {12, 5}};
  struct Rect b = {.lt = {1, 9}, .rb = {14, 3}};

  int res = is_crossed(a, b);

  printf("%d\n", res);

  return 0;
}

int is_crossed(struct Rect a, struct Rect b)
{
    // 1. Проверка пересечения по X
  int x_overlap = (a.lt.x < b.rb.x) && (b.lt.x < a.rb.x);
  
  // 2. Проверка пересечения по Y
  // Важно: lt.y > rb.y, и пересечение будет, если дно A ниже верха B, И дно B ниже верха A
  int y_overlap = (a.rb.y < b.lt.y) && (b.rb.y < a.lt.y);
  return x_overlap && y_overlap;
}