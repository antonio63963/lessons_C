#define AAA                 // определили макрос ААА


#ifdef AAA                  // если ААА есть, а он есть на первой строке)) то включаем код:
#include <stdio.h>
#include <assert.h>


int inc(int x);


int main()
{
    assert(inc(2) == 3);
    assert(inc(-2) == -1);
    return 0;
}
#endif                      // включаем до этой строки


// Код дальше есть всегда:


int inc(int x)
{
    return x + 1;
}

// Можно не определять AAA в коде программы, комментируя и раскомментируя строку с #define.
// При компиляции укажите gcc ключ -D с аргументом AAA. То есть для файла hello.c:
// gcc -Wall -Wextra -DAAA hello.c
// Ключ -D с аргументом AAA определяет макрос AAA, то есть работает, как #define AAA