#include <stdio.h>

int main()
{
  int price, delta, money;

  scanf("%d%d%d", &price, &delta, &money);

  int rest = money;
  int weekDay = 1;
  int currentPrice = price;
  int buysCount = 0;

  while (rest >= currentPrice)
  {
    printf("rest: %d, currentPrice: %d\n", rest, currentPrice);

    if (weekDay == 1 && rest != money)
    {
      currentPrice += delta;
    }
    if (weekDay == 7)
    {
      weekDay = 1;
    }
    else
    {
      weekDay++;
    }

    if (rest >= currentPrice)
    {
      rest -= currentPrice;
      buysCount++;
    }

    printf("AFTER +++ rest: %d, currentPrice: %d, buysCOunt: %d\n", rest, currentPrice, buysCount);
  }

  printf("%d\n", buysCount);

  return 0;
}