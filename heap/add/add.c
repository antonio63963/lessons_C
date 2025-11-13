#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char *a;           // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
  unsigned int n;    // наибольшая степень десяти
  unsigned int size; // размер выделенной динамической памяти в а
} Decimal;

Decimal *elong_set_int(unsigned int number)
{
  // сначала выделим память под саму структуру (фиолетовый прямоугольник)
  Decimal *px = malloc(sizeof(Decimal));

  if (number == 0)
  { // 0*10**0
    px->size = 1;
    px->n = 0;
    px->a = malloc(px->size);
    px->a[0] = 0;
    return px;
  }

  // number точно меньше 10 в 100, выделим память с запасом
  px->size = 100;
  px->a = malloc(px->size);

  for (px->n = 0; number > 0; px->n++)
  {
    px->a[px->n] = number % 10;
    number /= 10;
  }
  px->n--;

  // выделим памяти точно под хранение числа
  px->size = px->n + 1;
  px->a = realloc(px->a, px->size);
  return px;
}

Decimal *elong_add(const Decimal *a, const Decimal *b);

void elong_print(Decimal x)
{

  if (x.n == 0 && x.a[0] == 0)
  {
    printf("0\n");
    return;
  }

  for (int i = x.n; i >= 0; i--)
  {
    printf("%c", x.a[i] + '0');
  }

  printf("\n");
}

void elong_destroy(Decimal *px)
{
  free(px->a); // освобождаем желтый массив с цифрами
}

int main()
{
  Decimal *a;
  Decimal *b;
  Decimal *res;

  a = elong_set_int(147); // 147
  b = elong_set_int(13);  // 13

  res = elong_add(a, b); // res = a+b = 147+13 = 160

  elong_print(*res); // print 160

  elong_destroy(a);
  elong_destroy(b);
  elong_destroy(res);

  return 0;
}

Decimal *elong_add(const Decimal *a, const Decimal *b)
{
  Decimal *res = (Decimal *)malloc(sizeof(Decimal));
  if (res == NULL)
  {
    perror("malloc failed for Decimal struct");
    exit(1);
  }
  res->a = NULL;
  res->n = 0;
  res->size = 0;

  const Decimal *longest = a->n > b->n ? a : b;
  unsigned int max_n = longest->n;

  // Размер: max_n + 1 (самый старший разряд) + 1 (для возможного переноса)
  res->size = max_n + 2;

  res->a = (char *)malloc(res->size);
  if (res->a == NULL)
  {
    perror("malloc failed");
    exit(1);
  }

  char carry = 0;
  int sum_val = 0;

  for (unsigned int i = 0; i < res->size - 1; i++)
  {
    sum_val = carry;
    carry = 0;

    // Чтение разряда из A
    if (i <= a->n)
    {
      sum_val += a->a[i];
    }
    // Чтение разряда из B
    if (i <= b->n)
    {
      sum_val += b->a[i];
    }

    if (sum_val >= 10)
    {
      res->a[i] = sum_val - 10;
      carry = 1;
    }
    else
    {
      res->a[i] = sum_val;
      carry = 0;
    }
  }

  if (carry == 1)
  {
    // Записываем '1' в последнюю ячейку: max_n + 1
    res->a[res->size - 1] = 1;
    // Старший индекс теперь res->size - 1
    res->n = res->size - 1;
  }
  else
  {
    // Если переноса не было, старший индекс - это max_n
    res->n = max_n;

    // Опционально: уменьшение размера памяти (если не было переноса)
    unsigned int final_size = res->n + 1;
    if (res->size > final_size)
    {
      char *tmp = (char *)realloc(res->a, final_size);
      if (tmp != NULL)
      {
        res->a = tmp;
        res->size = final_size;
      }
    }
  }
  return res;
}
