#include <stdio.h>

int main()
{
  int n, i, j;
  scanf("%d", &n);
  int a[n];
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  
  
  for (i = 0; i < 10; i++)
  {
    
    int amount=0;
    if(i == a[i])
      amount++;
    
    printf("%d %d\n", a[i], amount);
  }

  return 0;
}