#include <stdio.h>
#include <ctype.h>

int main()
{
  int current_char; 


  int counter = 0;

  while ((current_char = getchar()) != EOF)
  {
    // printf("CHAR: %d\n", current_char);
    if (current_char == EOF || current_char == '\n')
    {
      break;
    }


    if (counter == 0 && current_char == 41)
    {
      counter = -100;
    }
    else if (current_char == 40)
    {
      counter++;
    }
    else if(current_char == 41)
    {
      counter--;
    } else {
      continue;
    }
    printf("counter: %d\n", counter);
  }
 

  printf("%s\n", counter == 0 ? "YES" : "NO");

  return 0;
}