#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

char *replace(const char *src);

int main()
{
  char s[N]; // нужно объявить переменную - место для читаемой строки
  char *d;   // указатель на динамический массив, память еще не выделена

  while (NULL != fgets(s, N, stdin))
  {
    printf("%s\n", s); // пока можем прочитать строку
    d = replace(s);    // тут память выделяем
    printf("+++%s+++\n", d);
    free(d); // тут память освобождаем
  }
  return 0;
}

char *replace(const char *src)
{
  char *bomb = "bomb";
  char *reBomb = "watermelon";
  int bombLen = strlen(bomb);
  int reBombLen = strlen(reBomb);
  int dif = reBombLen - bombLen;
  int countBombs = 0;
  // ищем количество bomb
  const char *temp = src;
  char *bombPtr;

  while ((bombPtr = strstr(temp, bomb)) != NULL)
  {
    countBombs++;
    temp += bombLen;
  }
  // выделяем память
  size_t srcLen = strlen(src);
  size_t newLen = srcLen + (dif * countBombs) + 1;
  char *newString = (char *)malloc(newLen);

  //запись в newString
  const char *currString = src;
  char *destString = newString;
  char *p;
  
  while((p = strstr(currString, bomb)) != NULL) {
    size_t n = p - currString;
    strncpy(destString, currString, n);
    destString += n;
    strcpy(destString, reBomb);
    destString +=reBombLen;
    currString = p + bombLen;
  }
  strcpy(destString, currString);

  return newString;
}
