#include <stdio.h>

void move(int *px, int *py, int dx, int dy) {
    int x = *px + dx;
    int y = *py + dy;
    
    printf("%d %d\n", x, y);
};

int main() {
    int x, y, mx, my;
    int *px = &x;
    int *py = &y;
    int *dx = &mx;
    int *dy = &my;
    
    scanf("%d%d%d%d", px, py, dx, dy);
    
    move(px, py, *dx, *dy);
    
    return 0;
};




