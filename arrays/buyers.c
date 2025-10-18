#include <stdio.h>

int main()
{
  int i, j, count = 0, n, timestamp, id, recept_id;

  scanf("%d", &n);
  int unique[n];
  for (i = 0; i < n; i++)
  {
    scanf("%d%d%d", &timestamp, &id, &recept_id);
    if (i == 0)
    {
      unique[i] = id;
      count++;
      continue;
    }
    int isExist = 0;
    for (j = 0; j < count; j++)
    {
      if (unique[j] == id)
      {
        isExist = 1;
        break;
      }
    }
    //printf("isEXIST: %d\n", isExist);
    if (isExist == 0)
    {
      unique[count] = id;
      count++;
      continue;
    }
    continue;
  }

  // for (j = 0; j < count; j++)
  // {
  //   printf("%d ", unique[j]);
  // }

  printf("%d\n", count);

  return 0;
}