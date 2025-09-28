#define time2min(h, m) ({ \
    ((h)/ 24 > 0) ? ((h)% 24) * 60 + m : (h) * 60 + (m);})

#include <stdio.h>

int main()
{
  int res = time2min(1, 20);

  printf("MINUTES: %d\n", res);

  return 0;
}