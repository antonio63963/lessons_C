#include <stdio.h>
#include <stdlib.h>
#define N 1000

int sortAB(const void *p1, const void *p2)
{
  char a = *(char *)p1;
  char b = *(char *)p2;

  return (a>b) - (a<b);
}

int main() {
  char s[N];
  char buffer_char;
  int count = 0;

  for(int i =0; i<N; i++) {
    scanf("%c", &buffer_char);
    printf("BUFFER: %c\n", buffer_char);
    if(buffer_char == ' ') {
      printf("UUUPS>>>>");
      continue;
    } 
    if(buffer_char == '.') {
      s[count] = buffer_char;
      count++;
      break;
    }
    s[count] = buffer_char;
    count++;
  }
  printf("src: ");
for(int i=0;i<count; i++) {
  printf("%c", s[i]);
}
printf("\n");
  qsort(s, count-1, sizeof(s[0]), sortAB);

  for(int i = 0; i<count; i++) {
    printf("%c", s[i]);
  }

  return 0;
}