#define min2time(mm, h, m) \
h = (((mm) / 60) / 24 > 0) ? (((mm) / 60) % 24): ((mm) / 60), \
m = (mm) % 60


#include <stdio.h>

int main()
{
  int h, m, mm;
  scanf("%d", &mm);

  min2time(mm, h, m);
  printf("%02d:%02d\n", h, m);

  min2time(mm + 65, h, m);
  printf("%02d:%02d\n", h, m);

  return 0;
}