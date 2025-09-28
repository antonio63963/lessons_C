#include <stdio.h>

int main(int argc, char const *argv[])
{
  // int var_i = 1240;
  // long double long_double = 234234.23424;
  // char str[] = "some string";
  // printf("value = %d\n longDouble = %Lf\n hohoho! %s\n", var_i, long_double, str);

  // // flags
  // //  формируется поле из 10 символов, куда заносится значение,
  // // выравнивание по правому краю
  // printf("[%10d]\n", var_i);
  // printf("[%10Lf]\n", long_double);

  // // выравнивание по левому краю
  // printf("[%-10d]\n", var_i);
  // // точность и 000128 длинна min
  // printf("Точность и длинна. \n [%.7d]\n", var_i);

  // // scanf - чтение байтов из буфера stdin
  // char byte;
  // int result = scanf("%c", &byte); // & определяет адрес сохранения
  // printf("SCANF: {result: %d, pressedValue: %c}\n", result, byte);
  // // с модификаторами
  // long long some_long = 0;
  // int result_some_long = scanf("%lld", &some_long);
  // printf("Some long Scanf: %d\n", result_some_long);

  // // несколько строк, чтаетмя как одна
  // printf("some\
  // llloooong\
  // string\n");
  // printf("hohohoho "
  //        "hekekek "
  //        "ohohho!\n");

         

  float weight; int tall;

  scanf("%f%d", &weight, &tall);
float m = tall / 100.0;
  float idx = weight / (m * m);

  printf("IDX: %f\n", idx);

  return 0;
}
