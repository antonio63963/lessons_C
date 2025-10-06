#include <stdio.h>

typedef struct
{
  int yy;  // год
  char mm; // месяц
  char dd; // день
} Data;

typedef struct
{
  int yy;      // год
  char season; // время года (зима - 0, весна - 1, лето - 2, осень - 3)
  int day;     // день от начала текущего времени года
} Season;

// получает параметры даты с консоли (три целых числа через тире:
// YYYY-MM-DD)
// Например, 2020-12-13
Data getData();

// Печатает дату в формате: YYYY-MM-DD завершая переносом строки (\n)
void printData(Data);

// конвертирует дату в формат Season и возвращает это значение
// зима с 1 декабря по конец февраля, весна - с 1 марта по 31 мая, лето - с 1 июня по 31 августа,
// осень - с 1 сентября по 30 ноября
Season convToSeas(Data);

//  печать времени года в формате: YYYY-SS-DD (SS - номер времени года,
// DD - день от начала времени года, завершая переносом строки
void printSeas(Season);

// ----------------
// MAIN
//---------------------

int main()
{
  Data dat;
  Season seas;
  dat = getData();
  printData(dat);
  seas = convToSeas(dat);
  printSeas(seas);

  return 0;
}

//-----------------
// FUNCTIONS
//------------------

Data getData()
{
  Data dat;
  scanf("%d-%hhd-%hhd", &dat.yy, &dat.mm, &dat.dd);
  return dat;
}

// Печатает дату в формате: YYYY-MM-DD завершая переносом строки (\n)
void printData(Data data)
{
  printf("%04d-%02hd-%02hd\n", data.yy, data.mm, data.dd);
}

// конвертирует дату в формат Season и возвращает это значение
// зима с 1 декабря по конец февраля, весна - с 1 марта по 31 мая, лето - с 1 июня по 31 августа,
// осень - с 1 сентября по 30 ноября
Season convToSeas(Data data)
{
  Season s;
  // char[] monthsDays = [31,28,31,30,31,30,31,31,30,31,30,31];
  s.yy = data.yy;
  if (data.mm == 12 || data.mm == 1 || data.mm == 2)
  {
    s.season = (char)0;
  }
  else if (data.mm >= 3 && data.mm <= 5)
  {
    s.season = (char)1;
  }
  else if (data.mm >= 6 && data.mm <= 8)
  {
    s.season = (char)2;
  }
  else if (data.mm >= 9 && data.mm <= 11)
  {
    s.season = (char)3;
  }

  if (s.season == 0)
  {
    if (data.mm == 12)
    {
      s.day = data.dd;
    }
    else if (data.mm == 1)
    {
      s.day = data.dd + 31;
    }
    else if (data.mm == 2)
    {
      s.day = data.dd + 31 * 2;
    }
  }
  else if (s.season == 1)
  {
    if (data.mm == 3)
    {
      s.day = data.dd;
    }
    else if (data.mm == 4)
    {
      s.day = data.dd + 31;
    }
    else if (data.mm == 5)
    {
      s.day = data.dd + 31 + 30;
    }
  }
  else if (s.season == 2)
  {
    if (data.mm == 6)
    {
      s.day = data.dd;
    }
    else if (data.mm == 7)
    {
      s.day = data.dd + 30;
    }
    else if (data.mm == 8)
    {
      s.day = data.dd + 31 + 30;
    }
  }
  else if (s.season == 3)
  {
    if (data.mm == 9)
    {
      s.day = data.dd;
    }
    else if (data.mm == 10)
    {
      s.day = data.dd + 30;
    }
    else if (data.mm == 11)
    {
      s.day = data.dd + 31 + 30;
    }
  }
  return s;
}

//  печать времени года в формате: YYYY-SS-DD (SS - номер времени года,
// DD - день от начала времени года, завершая переносом строки
void printSeas(Season s)
{
  printf("%04d-%02hd-%02hhd\n", s.yy, s.season, s.day);
}