#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct
{
  int n;
  int size;
  Data *a;
} Stack;

Stack *stack_create(int size);
void stack_push(Stack *s, Data x);
Data stack_pop(Stack *s);
Data stack_get(Stack *s);
void stack_print(Stack *s);
int stack_size(Stack *s);
int stack_is_empty(Stack *s);
void stack_clear(Stack *s);
Stack *stack_destroy(Stack *s);

void test0()
{
  Stack *sp = stack_create(3);
  Data x;
  printf("is_empty=%d\n", stack_is_empty(sp)); // is_empty=1
  printf("size=%d\n", stack_size(sp));         // size=0

  stack_push(sp, 5);
  stack_push(sp, 19);
  stack_push(sp, -2);
  stack_print(sp); // 5 19 -2

  stack_push(sp, 27);
  stack_print(sp); // 5 19 -2 27

  printf("is_empty=%d\n", stack_is_empty(sp)); // is_empty=0
  printf("size=%d\n", stack_size(sp));         // size=4

  x = stack_pop(sp);
  printf("x=%d\n", x); // x=27

  x = stack_pop(sp);
  printf("x=%d\n", x); // x=-2

  stack_print(sp); // 5 19

  while (!stack_is_empty(sp))
  {
    x = stack_pop(sp);
    printf("x=%d\n", x);
    stack_print(sp);
  }
  // x=19
  // 5
  // x=5
  // пустая строка

  if (NULL == stack_destroy(sp))
    printf("end\n"); // end
}

int main()
{
  test0();

  return 0;
}

Stack *stack_create(int size)
{
  Stack *s = malloc(sizeof(Stack));
  if (s == NULL)
  {
    perror("OOOPS...");
    return NULL;
  }
  if (size < 0)
  {
    size = 10;
  }
  s->n = 0;
  s->size = size;
  s->a = malloc(size * sizeof(Data));
  if (s->a == NULL)
  {
    perror("OOPS... Failure on allocte data arr");
    free(s);
    s = NULL;
    return s;
  }
  return s;
}

void stack_push(Stack *s, Data x)
{
  if (s->n == s->size)
  {
    int new_s = (s->size + 10);
    s->a = realloc(s->a, new_s * sizeof(Data));
    s->size = new_s;
  }
  s->a[s->n] = x;
  s->n++;
}
Data stack_pop(Stack *s)
{
  if (s == NULL || s->n == 0)
  {
    perror("Pop used on empty stack!\n");
    return (Data)0;
  }
  Data d = s->a[s->n - 1];
  s->n--;
  return d;
}
Data stack_get(Stack *s)
{
  if (s == NULL || s->n == 0)
  {
    fprintf(stderr, "GET used on empty stack. Returning 0\n");
    return (Data)0;
  }
  return s->a[s->n - 1];
}
void stack_print(Stack *s)
{
  for (int i = 0; i < s->n; i++)
  {
    printf("%d ", s->a[i]);
  }
  printf("\n");
}
int stack_size(Stack *s)
{
  return s->n > 0 ? s->n : 0;
}
int stack_is_empty(Stack *s)
{
  return s->n == 0;
}
void stack_clear(Stack *s)
{
  if (s == NULL)
    return;
  Data *cleaned = realloc(s->a, 10 * sizeof(Data));
  if (cleaned == NULL)
  {
    perror("Failure on realocate arr... On clean stack.");
    return;
  }
  s->a = cleaned;
  s->n = 0;
  s->size = 10;
}
Stack *stack_destroy(Stack *s)
{
  free(s->a);
  free(s);
  s = NULL;
  return s;
}
