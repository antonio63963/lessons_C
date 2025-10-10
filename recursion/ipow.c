#include <stdio.h>

long long int ipow(long long int a, unsigned int n, unsigned int *depth);

int main()
{

  int d = 0;
  long long int res1 = ipow(2, 32, &d); // res = 4294967296, d = 6
  printf("%lld %d\n", res1, d);

  long long int res2 = ipow(3, 12, &d); // res = 531441, d = 5

  printf("%lld %d\n", res2, d);

  long long int res3 = ipow(-3, 11, &d); // res = 531441, d = 5

  printf("%lld %d\n", res3, d);

  return 0;
}

long long int ipowNest(long long int a, unsigned int n, unsigned int *depth)
{
  if (n == 0)
  {
    return 1;
  }
  // Рекурсивный вызов: вычисляем power(base, exponent / 2)
  // Это сохраняется в temp, чтобы избежать двойного вычисления.
  (*depth)++;
  long long int temp = ipowNest(a, n / 2, depth);
  
  // 3. Если степень четная: a^n = (a^(n/2))^2
  if (n % 2 == 0)
  {
    return temp * temp;
  }
  // 4. Если степень нечетная: a^n = a * (a^((n-1)/2))^2
  else
  {
    return a * temp * temp;
  }
}

long long int ipow(long long int a, unsigned int n, unsigned int *depth) {
  *depth = 0;
  long long int res = ipowNest(a, n, depth);
  return res;
}
