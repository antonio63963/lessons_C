#include <stdio.h>

#define R2 (5 * 5)

int main()
{
  int n;
  int x;
  // int curretn= 0;
  int oddSum = 0;

  scanf("%d", &n);

  // while (1 == scanf("%d", &x))
  // { 
  //   printf("currrent: %d\n", curretn);
  //   if (curretn < n)
  //   {
  //     curretn++;
  //     if (x % 2 == 0)
  //     {
  //       oddSum+=x;
  //     }
  //   }
  //   else
  //   {
  //     printf("%d\n", oddSum);
  //     return 0;
  //   }
  // }

  for(int curretn =0; curretn < n; curretn++) {
    if(1 == scanf("%d", &x)) {
      if (x % 2 == 0)
      {
        oddSum+=x;
      }
    }

  }
  printf("%d\n", oddSum);
  return 0;
}
