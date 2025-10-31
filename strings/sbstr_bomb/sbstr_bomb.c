#include <stdio.h>
#include <string.h>

int main() {
  char s[1000];
  int isBomb = 0;

  while(1==scanf("%1000s", s))  {
    // printf("%s\n", s);
    if(strstr(s, "bomb") != NULL) {
      isBomb = 1;
      break;
    }
  }

  printf("%s\n", isBomb ? "YES": "NO");
  return 0;
}