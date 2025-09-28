#include <stdio.h>

int mirrorPoint(int y) {
    return y -=(y*2); 
};
   
void mirror_seg(int *px1, int *py1, int *px2, int *py2) {
    *py1 = mirrorPoint(*py1);
    *py2 = mirrorPoint(*py2);
    
    printf("%d %d %d %d", *px1, *py1, *px2, *py2);
};

int main() {
    signed int x1, y1, x2, y2;
    int *px1 = &x1;
    int *py1 = &y1;
    int *px2 = &x2;
    int *py2 = &y2;
    
    scanf("%d%d%d%d", px1, py1, px2, py2);
    
    mirror_seg(px1, py1, px2, py2);
    
    return 0;  
}
