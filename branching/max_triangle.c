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

struct Rect *max(struct Rect *pa, struct Rect *pb);
float getAreaTriangle(struct Rect t);


int main()
{
  struct Rect t1, t2;

  scanf("%d%d%d%d", &t1.lt.x, &t1.lt.y, &t2.lt.x, &t2.lt.y);
}
//functions

float getAreaTriangle(struct Rect t)
{
  int height = t.lt.y - thridP.y;
  int width = t.lt.x - t.rb.x;

  float area = (height * width) / 2;
  return area;
};

struct Rect *max(struct Rect *pa, struct Rect *pb)
{

  float area1 = getAreaTriangle(*pa);
  float area2 = getAreaTriangle(*pb);

  if(area1 > area2) {
    return pa;
  } else {
    return pb;
  }

}