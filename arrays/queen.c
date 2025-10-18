#include <stdio.h>

// c - clubs, трефы, ♣
//  s - spades, пики, ♠️
//  h - hearts, червы, ♥️
//  d - diamond, бубны, ♦️

struct Card
{
  char rank; // достоинство
  char suit; // масть
};

int check(struct Card *hand);

    int main()
{
  struct Card hand1[] = {{'Q', 's'}, {'A', 'h'}, {'9', 'd'}, {0, 0}};
  struct Card hand2[] = {{'2', 's'}, {'A', 'h'}, {0, 0}};

  int res = check(hand2);
  printf("isQ: %d\n", res);

  return 0;
}

int check(struct Card *hand)
{
  int isFin = 0;
  int i = 0;
  int isQ = 0;
  while (isFin == 0)
  {
    if (hand[i].rank == 'Q' && hand[i].suit == 's')
    {
      isQ = 1;
      break;
    }
    else if (hand[i].rank == 0)
    {
      isFin = 1;
      break;
    }
    else
    {
      i++;
      continue;
    }
  }

  return isQ;
}