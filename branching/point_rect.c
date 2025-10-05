// {−3≤x≤2 −4≤y≤6​
#include <stdio.h>

int isContains(float x , float y) {

  if(x >= -3 && x <= 2 && y >= -4 && y <= 6) {
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