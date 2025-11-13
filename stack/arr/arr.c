#define N 8
typedef int Data;

typedef struct
{
  Data a[N];      // место для данных
  unsigned int n; // сколько данных хранится
} Stack;

void stack_init(Stack *s);
void stack_push(Stack *s, Data x);
Data stack_pop(Stack *s);
Data stack_get(Stack *s);
void stack_clear(Stack *s);
void stack_print(Stack *s);
int stack_size(Stack *s);
int stack_is_empty(Stack *s);
int stack_is_full(Stack *s);

int main()
{

  return 0;
}

void stack_init(Stack *s)
{
  s->n = 0;
}
void stack_push(Stack *s, Data x)
{
  s->a[s->n] = x;
  s->n++;
}
Data stack_pop(Stack *s)
{
  s->n--;
  return s->a[s->n];
}
Data stack_get(Stack *s)
{
  return s->a[s->n];
}
void stack_clear(Stack *s)
{
  s->n = 0;
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
  return s->n > 0 ? s->n + 1 : 0;
}
int stack_is_empty(Stack *s)
{
  return s->n == 0 ? 1 : 0;
}
int stack_is_full(Stack *s)
{
  return s->n == sizeof(s->a) / sizeof(s->a[0]);
}
