#include <stdio.h>

void sort2(int * a, int * b);
void sort3(int * x, int * y, int * z);

int main()
{
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    sort3(&x, &y, &z);
    printf("%d %d %d\n", x, y, z);
    return 0;
}

void sort2(int * a, int * b) {
    int a1 = *a;
    int b1 = *b;
    *a = a1 < b1 ? a1 : b1;
    *b = b1 > a1 ? b1 : a1;
}
void sort3(int * x, int * y, int * z) {
  sort2(x, y);
  sort2(x, z);
  sort2(y, z);
}