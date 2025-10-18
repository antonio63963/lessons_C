

#include <stdio.h>

// Максимальное количество цифр
#define N 100
#define min(a, b) a > b ? b : a
#define max(a, b) a < b ? b : a

typedef struct
{
  // a[i] хранит коэффициент (цифру) при 10^i
  // a[0] - младшая цифра, a[n] - старшая цифра
  char a[N];
  unsigned int n; // наибольшая степень десяти (индекс старшей цифры)
} Decimal;

/**
 * Печатает длинное число, представленное структурой Decimal.
 * Печать производится от старшей цифры (a[n]) к младшей (a[0]).
 */
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

Decimal add(Decimal x, Decimal y)
{
  Decimal res;
  int i;
  int carry = 0; // Переменная для хранения переноса (0 или 1)

  int max_len = x.n < y.n ? y.n : x.n;

  for (i = 0; i < 100; i++)
  {
    res.a[i] = 0;
  }

  for (i = 0; i <= max_len; i++)
  {
    int digit_x = (i <= x.n) ? x.a[i] : 0;
    int digit_y = (i <= y.n) ? y.a[i] : 0;

    int sum = digit_x + digit_y + carry;

    res.a[i] = sum % 10;

    carry = sum / 10;
  }

  if (carry > 0)
  {
    if (i < 100)
    {
      res.a[i] = carry;
      res.n = i; // Новая наибольшая степен
    }
    else
    {

      res.n = max_len;
    }
  }
  else
  {
    res.n = max_len;
  }

  return res;
}
// -------------------------------------------------------------------

int main()
{
  Decimal x = {{7, 4, 1}, 2}; // set number 147
  Decimal y = {{3, 1}, 1};    // set number 13
  Decimal res;

  res = add(x, y);  // res = x+y = 147+13 = 160
  elong_print(res); // print 160

  return 0;
}
