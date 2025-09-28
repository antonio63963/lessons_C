#include <stdio.h>f

int main(int argc, char const *argv[])
{
  int value = getchar(); // получение с терминала strin 
  int res = putchar(value); // передача в stdout
  printf("\n%d\n", res);
  return 0;
}
