#include <stdio.h>

#define N 100
typedef struct
{
  char a[N];      // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
  unsigned int n; // наибольшая степень десяти
} Decimal;

void elong_print(Decimal x);
void elong_set(Decimal *res, const char str[]);

// MAIN=========================================================

int main()
{
  Decimal res;
  elong_set(&res, "12345678901234567890"); // res = 12345678901234567890

  elong_print(res); // print 12345678901234567890

  return 0;
}

//=========================================================
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

void elong_set(Decimal *res, const char str[])
{
  int lengthStr = 0;
  int strIdx = 0;
  while (str[lengthStr] != '\0')
  {
    // printf("%d\n", str[lengthStr]);
    lengthStr++;
  }

  int resIdx = 0;
  for (int i = lengthStr-1; i >= 0; i--)
  {
    res->a[resIdx] = str[i] - '0';
    resIdx++;
  }
  res->n = lengthStr-1;
}