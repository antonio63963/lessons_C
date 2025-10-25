#include <stdio.h>
#define STR(N) #N
#define CONCAT(a, b) STR(a)" = "b"\n"
#define DBG_PRN(format, arg) printf(CONCAT(arg, format), arg)

int main()
{
  float x = 3.14;
  int a = 56;
  char *str = "Hello";

  DBG_PRN("%.1f", x); // x = 3.1
  DBG_PRN("%d", a);   // a = 56
  DBG_PRN("%s", str); // str = Hello

  return 0;
}