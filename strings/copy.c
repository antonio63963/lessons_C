#include <stdio.h>
#include <string.h>

char *my_strcat(char *dest, const char *src);

int main()
{
  char a[20] = "Hello";
  char *b = "World";
  my_strcat(a, b);
  printf("%s\n", a);
  return 0;
}

//===================
char *my_strcat(char *dest, const char *src)
{
  int i = 0;
  for (i; dest[i] == '\0'; i++)
  {
  }
  return strcpy(&dest[i], src);
}

