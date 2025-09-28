#include <stdio.h>
#define A = 3
#define cube(x) x *x *x
#define goodCube(x) ((x) * (x) * (x))

int main()
{
  int res = cube(3 + 2);
  int res2 = cube(3 + 2);

  printf("CUBE: %d,\n GOOD CUBE: %d\n", res, res2);

  // встроенные макросы
  printf("%s %d: %s\n", __FILE__, __LINE__, __FUNCTION__);

#define _WIN64
#ifdef __linux__ // или #if defined (__linux__)
  // много кода, который будет работать в Linux
  printf("hoho! LINUX...\n");
#elif defined(_WIN64)
  много кода для 64 - битной Windows
#else
  printf("Какая у вас операционная система?\n");
#endif

      return 0;
}