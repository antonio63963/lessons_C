#include <stdio.h>


int x = 5;


void foo() {
    x = x + 1;
}


int main() {
    foo();
    foo();
    printf("%d\n", x);
    return 0;
}
