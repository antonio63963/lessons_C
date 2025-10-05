#include <stdio.h>

int main()
{
  int dWidth, dHeight, fWidth, fHeight, fDeep;

  scanf("%d%d", &dWidth, &dHeight);
  scanf("%d%d%d", &fWidth, &fHeight, &fDeep);

  
  int res= 0;

  if((fWidth < dWidth && fHeight < dHeight) || (fWidth < dHeight && fHeight < dWidth))
  {
    res = 1;
  }
  if ((fDeep < dHeight && fWidth < dWidth) || (fDeep < dWidth && fWidth < dHeight)) {
    res = 1;
  }
  if ((fDeep < dHeight && fHeight < dWidth) || (fDeep < dWidth && fHeight < dHeight)) {
    res = 1;
  }
  printf("%s %d\n", res ? "YES" : "NO");
}