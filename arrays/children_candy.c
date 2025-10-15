#include <stdio.h>

int delim(int a[], int i, int j);
// Функция делит конфеты детей a[i] и a[j].
// Отдает школьнику (return) лишние конфеты.

int all_equal(int a[], int n);
// Проверяет, все ли числа в массиве a одинаковые.
// Возвращает 1 (все одинаковые) или 0 (не все)
// вы писали раньше такую задачу

int make_all_happy(int a[], int n);
// Дети делят конфеты, "лишние" конфеты возвращают

int main()
{
  int a[100];   // ребенок i имеет a[i] конфет
  int n, i = 0; // всего детей

  scanf("%d", &n); // читаем входные данные
  for (i = 0; i < n; i++)
    scanf("%d", a + i);

  int schoolboy = make_all_happy(a, n); // делим
  printf("%d %d\n", schoolboy, a[0]);
     // печатаем ответ
  for( i=0; i < n; i++) {
    printf("fin: %d, ", a[i]);
  }

  return 0;
}

int delim(int a[], int i, int j)
{
  int sum = a[i] + a[j];
  int equalM = sum / 2;
  printf("HALF: %d, SUM: %d, a[i]: %d, a[j]: %d\n", equalM, sum, a[i], a[j]);
  a[i] = equalM;
  a[j] = equalM;
  return sum - equalM * 2;
}

int all_equal(int a[], int n)
{
  int i = 0;
  for (i; i < n; i++)
  {
    if (a[0] != a[i])
    {
      return 0;
    }
  }
  return 1;
}

int make_all_happy(int a[], int n)
{
  int i = 0;
  int candeis = 0;

  while (!all_equal(a, n))
  {
    if (i == n - 1)
    {
      candeis += delim(a, i, 0);
      i = 0;
    }
    else
    {
      candeis += delim(a, i, i + 1);
      i++;
    }
    printf("Candies: %d\n", candeis);
  }
  return candeis;
}