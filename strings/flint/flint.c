#include <stdio.h>
#include <string.h>

int main()
{
  char s[10]; // подумайте, почему 10 символов должно хватить, если гарантируют именно такие входные данные
  int steps, x =0, y = 0;

  for (int i = 0;; i++)
  {
    scanf("%9s", s);
    if (0 == strcmp(s, "Treasure!")) {
      break;
    }

    scanf("%d", &steps);
    if(0==strcmp(s, "North")) {
      y+=steps;
    }else if(0==strcmp(s, "South")) {
      y-=steps;
    }else if(0==strcmp(s, "East")) {
      x+=steps;
    }else if(0==strcmp(s, "West")) {
      x-=steps;
    }
  }

  printf("%d %d\n", x, y);

  return 0;
}