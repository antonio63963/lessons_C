#include <stdio.h>


int main()
{
    int money[] = {1, 2, 5, 10, 50, 100, 500, 1000, 5000};
    int mSize = sizeof(money) / sizeof(money[0]);
    int input, i;
    scanf("%d", &input);

    int rest = input;

    for(i = mSize-1; i>=0; i--) {
        int amount = rest / money[i];
        rest = rest - amount * money[i];
        printf("%d %d\n", money[i], amount);
    }

    return 0;
}
