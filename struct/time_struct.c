#include <stdio.h>

typedef struct
{
  int h;   // часы
  int min; // минуты (от 0 до 59)
} TicTac;

// получает показание часов a и возвращает показание этих часов
// через min минут, .
TicTac after(TicTac a, int min);

// "переводит" вперед стрелки этих часов (me)
// на a.h часов и a.min минут
void forward(TicTac *me, TicTac a);

// "переводит" назад стрелки этих часов (me)
// на a.h часов и a.min минут
void backward(TicTac *me, TicTac a);

// проверяет совпадают ли показания часов a и b
// если совпадают, возвращает 1, если нет - 0
int isEqualTime(TicTac a, TicTac b);

// печатает показания этих часов в формате hh:mm\n
void printTic(TicTac a);

int main()
{
  TicTac a, b, c;
  int mk;

  scanf("%d:%d", &(a.h), &(a.min));
  scanf("%d", &mk);
  scanf("%d:%d", &(b.h), &(b.min));

  printf("equal: %d\n", isEqualTime(a, b));
  c = after(a, mk);
  printf("after: ");
  printTic(c);

  c = a;
  printf("forward: ");
  forward(&a, b);
  printTic(a);

  printf("backward: ");
  backward(&c, b);
  printTic(c);

  return 0;
}

TicTac after(TicTac a, int min)
{
  int freshMin = (a.min + min) % 60;
  int freshHours = a.h + (int)((a.min + min) / 60);
  a.h = freshHours >= 12 ? freshHours % 12 : freshHours;
  a.min = freshMin;
  return a;
}

void forward(TicTac *me, TicTac a)
{
  TicTac tic = after(*me, a.min);
  tic.h = (tic.h + a.h) % 12;

  *me = tic;
}

void backward(TicTac *me, TicTac a)
{
  int restH = 0;
  int min = (me->min - a.min) % 60;
  if (min >= 0)
    me->min = min;
  else {
    me->min = 60 + min;
    restH++;
  }

  int hours = (me->h - a.h - restH) % 12;
  if (hours >= 0)
    me->h = hours;
  else
    me->h = 12 + hours;
}               

int isEqualTime(TicTac a, TicTac b)
{
  int h = a.h == b.h;
  int m = a.min == b.min;
  return h && m ? 1 : 0;
}

void printTic(TicTac a)
{
  printf("%2.2d:%2.2d\n", a.h, a.min);
}