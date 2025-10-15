#include <stdio.h>

int isEqualAll(int *arr, int n)
{
  int i = 0;
  for (i; i < n; i++)
  {
    if (arr[0] != arr[i])
    {
      return 0;
    }
  }
  return 1;
}

void tossMoney(int *arr, int n, int *moneyK)
{
  printf("moneyK = %d, i = %d\n", *moneyK, arr[0]);

  int i = 0;
  for (i; i < n; i++)
  {
    if (i == n - 1)
    {

      int sum = arr[i] + arr[0];
      int equalM = sum / 2;

      arr[i] = equalM;
      arr[0] = equalM;
      *moneyK += sum - equalM * 2;
      if (!isEqualAll(arr, n))
      {
        tossMoney(arr, n, moneyK);
      }
      continue;
    }

    int sum = arr[i] + arr[i + 1];
    int equalM = sum / 2;
    printf("HALF: %d, SUM: %d, a[i]: %d, a[j]: %d\n", equalM, sum, arr[i], arr[i+1]);

    arr[i] = equalM;
    arr[i + 1] = equalM;
    *moneyK += sum - equalM * 2;
    
  }
}

int main()
{
  int n, i;
  scanf("%d", &n);

  int workers[n];
  int dWorkers[n];

  for (i = 0; i < n; i++)
  {
    scanf("%d", &workers[i]);
  }

  int moneyK = 0;

  tossMoney(workers, n, &moneyK);

  printf("%d %d\n", moneyK, workers[0]);

  return 0;
}