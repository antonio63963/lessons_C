
struct Time {
    int h;
    int m;
};

// Этот код уже будет в проверяющей системе:
#include <stdio.h>

int main()
{
    struct Time t;
    scanf("%d:%d", &t.h, &t.m);
    printf("%02d:%02d\n", t.h, t.m);
    return 0;
}
