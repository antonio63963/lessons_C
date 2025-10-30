#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BOMB "bomb"
#define REBOMB "watermelon"

int main()
{
  char src[1000];
  char dest[1000];
  int bombLen = strlen(BOMB);
  int reLen = strlen(REBOMB);
  char *s;
  char *d;

  while (fgets(src, sizeof(src), stdin) != NULL)
  {
    // printf("%s\n", s);

    s = src;
    d = dest;
    char *p;

    while ((p = strstr(s, BOMB)) != NULL)
    {
      size_t n = p - s;
      strncpy(d, s, n);
      d = d + n;
      strcpy(d, REBOMB);
      d = d + reLen;
      s = p + bombLen;
    }
    strcpy(d, s);

    printf("%s", dest);
    // printf("SRC: %s", src);
  }

  return 0;
}