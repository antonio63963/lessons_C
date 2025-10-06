#include <stdio.h>

int main()
{
  int k, p1, p2, p3;

  scanf("%d\n%d\n%d\n%d", &k, &p1, &p2, &p3);
  int sum = p1 + p2 + p3;

  int p12 = (p1 + p2) <= k && p3 <= k;
  int p13 = (p3 + p1) <= k && p2 <= k;
  int p23 = (p3 + p2) <= k && p1 <= k;

  int isCan = p12 || p13 || p23;

  printf("%s\n",  !isCan ? "NO" : "YES");

  return 0;
}