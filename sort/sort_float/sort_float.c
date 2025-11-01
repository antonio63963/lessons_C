#include <stdio.h>
#include <stdlib.h>

int sortAB(const void *p1, const void *p2)
{
  float a = *(float *)p1;
  float b = *(float *)p2;

  // if (a > b)
  // {
  //   return 1;
  // }
  // else if (a < b)
  // {
  //   return -1;
  // }
  // else
  // {
  //   return 0;
  // }
  return (a>b) - (a<b);
}

int main()
{
  int n;
  scanf("%d", &n);

  float arr[n];

  for(int i =0; i<n; i++) {
    scanf("%f", &arr[i]);
  }

  qsort(arr, n, sizeof(arr[0]), sortAB);

  for(int i =0; i<n; i++) {
    printf("%0.2f ", arr[i]);
  }

  return 0;
}