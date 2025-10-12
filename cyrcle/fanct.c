#include <stdio.h>

#define R2 (5 * 5)

int main()
{
  int n;
  int fact;

  scanf("%d", &n);
  fact = n ? n : 1;
  for (int curr = n - 1; curr > 0; curr--)
  {
    printf("BEFORE:curr: %d, fact: %d\n", curr, fact);
    if(curr <= 0) {
      fact = 1;
      break;
    }
    fact *= curr;
    printf("curr: %d, fact: %d\n", curr, fact);
  }
  printf("%d\n", fact);
  return 0;
}
