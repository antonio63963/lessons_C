#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point
{
  int x;
  int y;
};

int cmp_Point(const void *p1, const void *p2);

int main()
{
  struct Point a, b;
  scanf("%d%d", &a.x, &a.y);
  scanf("%d%d", &b.x, &b.y);

  int res = cmp_Point(&a, &b);

  if (res < 0)
    printf("<\n");
  else if (res > 0)
    printf(">\n");
  else
    printf("=\n");

  return 0;
}

int getGipot(int x, int y) {
unsigned long long sum = (unsigned long long)x * x + (unsigned long long)y * y;
printf("long: %lld\n", sum);
  return sqrt(sum);

}

int cmp_Point(const void *p1, const void *p2)
{
  const struct Point *a = (const struct Point *)p1; // const struct - потому что не typedef
  const struct Point *b = (const struct Point *)p2;

unsigned  int aDis = getGipot(abs(a->x), abs(a->y));
unsigned  int bDis = getGipot(abs(b->x), abs(b->y));
printf("aDis = %d, bDis = %d\n", aDis, bDis);
  return (aDis > bDis) - (aDis < bDis);
}
