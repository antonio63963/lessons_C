#include <stdio.h>

// мальчики до 10 лет не участвуют в соревнованиях (бегут 0 км);
// мальчики с 10 до 12 лет (включительно) бегут 3 км;
// мальчики с 13 до 15 лет (включительно) бегут 5 км;
// остальные участники бегут 10 км.
//

int getKm(int age)
{
  int km = 0;

  if (age < 10)
  {
    km = 0;
  }
  else if (age >= 10 && age <= 12)
  {
    km = 3;
  }
  else if (age > 12 && age <= 15)
  {
    km = 5;
  }
  else
  {
    km = 10;
  }
  return km;
}

int main()
{
  int age;

  scanf("%d", &age);
  printf("%d\n", getKm(age));

  return 0;
}