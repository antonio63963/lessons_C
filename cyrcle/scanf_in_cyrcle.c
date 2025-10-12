#include <stdio.h>


#define R2 (5*5)


int main()
{
    int x;
    int total = 0, tall = 0;
    while(1 == scanf("%d", &x)) {     // ПОКА прочитано два числа
        if (x > 170) {
          tall ++;
        }
        total++;
      }
      printf("%d %d\n", total, tall);
    return 0;
}
