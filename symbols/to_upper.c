#include <stdio.h>
#define DIF ('a' - 'A')

int main() {
  char letter;

  scanf("%c", &letter);

  printf("%c\n", letter + DIF);
  return 0;
}