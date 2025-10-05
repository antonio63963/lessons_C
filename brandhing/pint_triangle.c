// ​y≤3+x y≤3−x y≥−2​

#include <stdio.h>

int isContains(float x , float y) {

  if(y <= 3+x && y <= 3-x && y >= -2) {
    return 1;
  }else {
    return 0;
  }
}

int main() {
  float x, y;

  scanf("%f%f", &x, &y);
  int res = isContains(x, y);
  printf("%s\n", res ? "YES" : "NO");
}