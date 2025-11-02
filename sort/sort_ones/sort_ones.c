#include <stdio.h>
#include <stdlib.h>

int cmp_custom(const void *p1, const void *p2)
{
  const int a = *(const int *)p1;
  const int b = *(const int *)p2;

  int temp_a = a;
  int temp_b = b;
  int digit_a, digit_b;

  // Сравниваем разряды, начиная с единиц (k=0)
  for (int k = 0; k < 1000; k++)
  {

    // Получаем текущие разряды
    digit_a = temp_a % 10;
    digit_b = temp_b % 10;

    // Если разряды различаются, возвращаем результат сравнения
    if (digit_a != digit_b)
    {
      return digit_a - digit_b;
    }

    // Переходим к следующему разряду
    temp_a /= 10;
    temp_b /= 10;

    // Если оба числа стали равны 0
    if (temp_a == 0 && temp_b == 0)
    {
      return 0;
    }
  }

  return 0;
}

int main()
{
  int n;

  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  qsort(arr, n, sizeof(arr[0]), cmp_custom);

  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  printf("\n");

  return 0;
}