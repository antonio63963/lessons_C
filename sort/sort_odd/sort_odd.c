#include <stdio.h>
#include <stdlib.h>



int mySort(const void *p1, const void *p2)
{
   int a = *(int *)p1;
   int b = *(int *)p2;

  return (a > b) - (a < b);
}

int main()
{
  int n;

  scanf("%d", &n);
  int arr[n];
  int even_nums[n];
  int even_inexes[n];
  int evenCount = 0;

  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
    if (arr[i] % 2 == 0)
    {
      even_nums[evenCount] = arr[i];
      even_inexes[evenCount] = i;
      evenCount++;
    }
  }

  qsort(even_nums, evenCount, sizeof(even_nums[0]), mySort);

  for (int i = 0; i < evenCount; i++)
  {
    arr[even_inexes[i]] = even_nums[i];
  }

  for(int i=0; i<n;i++) {
  }
  printf("\n");
  // печать
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}