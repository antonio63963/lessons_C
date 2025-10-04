#include <stdio.h>

typedef struct
{
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} Color;

// считать RGB-формат с консоли
Color getColor();
// перевод из RGB-формата в число
unsigned long long convertToHTML(Color);
// преобразование числа цвета в RGB-формат
Color convertToRGB(unsigned long long);
// печать цвета в RGB-формате (печать значений в десятичном виде через пробел)
// red green blue:
// 255 128 222
// Печатать только числа через пробел и \n в конце!!!
void printRGB(Color);

// печать цвета в HTML-формате и \n в конце.
// Примеры: FFA902 0AA3FF
void printHTML(Color);

int main()
{
  Color z, z2;
  unsigned long long html;

  z = getColor();
  printRGB(z);

  html = convertToHTML(z);
  printf("%llu\n", html);
  printHTML(z);

  z2 = convertToRGB(html);
  printRGB(z2);

  return 0;
}

Color getColor()
{
  Color color;
  scanf("%hhd%hhd%hhd", &color.red, &color.green, &color.blue);
  return color;
}

unsigned long long convertToHTML(Color rgb)
{
  unsigned int hex_color = rgb.red << 16 |
                           rgb.green << 8 |
                           rgb.blue;
  return (unsigned long long)hex_color;
}

Color convertToRGB(unsigned long long hex_color)
{
  Color rgb;
  rgb.red = hex_color >> 16;
  rgb.green = (hex_color >> 8) & 0xFF;
  rgb.blue = hex_color & 0xFF;

  return rgb;
}

void printRGB(Color color)
{
  printf("%hd %hd %hd\n", color.red, color.green, color.blue);
}

void printHTML(Color color)
{
  int hex_color = convertToHTML(color);
  printf("%06X\n", hex_color);
}