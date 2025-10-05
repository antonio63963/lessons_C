#include <stdio.h>

int main()
{
  int dWidth, dHeight, fWidth, fHeight, fDeep;

  scanf("%d%d", &dWidth, &dHeight);
  scanf("%d%d%d", &fWidth, &fHeight, &fDeep);

  
  int res= 0;

  if(fWidth < dWidth || fWidth < dHeight)
  {
    res += 1;
  }
  if (fHeight < dHeight || fHeight < dWidth) {
    res += 1;
  }
  if(fDeep < dWidth || fDeep < dHeight) {
    res += 1;
  }
  printf("%s %d\n", res > 1 ? "YES" : "NO", res);
}