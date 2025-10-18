#include <stdio.h>
// #include <ctype.h>

#define toNum(num) num - 48

int main()
{
  int people;
  int knightsAmount = 0;

  scanf("%d\n", &people);
  int input[people];
  int c;

  for (int i = 0; i < people; i++)
  {
    c = getchar();
    if (c == EOF || c == '\n')
    {
      fprintf(stderr, "\nОшибка: Введено менее 4 символов.\n");
      return 1;
    }
    int numC = toNum(c);
    if (numC == 0 || numC == 1)
    {
      input[i] = numC;
    }
    else
    {
      fprintf(stderr, "\n Только 0 или 1!");
    }
  }

  

  for (int i = 0; i < people; i+=2)
  {
    int next = input[i + 1];
    printf("idx: %d\n", i);
    if (input[i] == 0 && next == 1)
    {
      knightsAmount++;
    }
    else if (input[i] == 1 && next == 0)
    {
      knightsAmount++;
    }
    else if (input[i] == 0 && next == 0)
    {
      knightsAmount++;
    }
  }

  printf("%d\n", knightsAmount);

  return 0;
}