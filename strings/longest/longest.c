#include <stdio.h>
#include <string.h>


int main() {
  char s[1000];
  char longW[1000] ;
  int len = 0;

  //fgets(s, 1000, stdin);
  while(1 == scanf("%1000s", s)) {
    //printf("%s\n", s);
    int curLen = strlen(s);
    if(len == 0 || len < curLen) {
      len = curLen;

      strcpy(longW, s);
    }
  }

  printf("%s %d\n", longW, len);
  return 0;
}