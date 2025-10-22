#include <stdio.h>
#define W 46 //.
#define B '*' // 42 // *
#define maxL 101

int getBlackAmount(int n, char field[maxL][maxL]) {
  int amountB = 0;
  for(int i = 0; i< n; i++) {
    for(int j = 0; j<n; j++) {
      //printf("SIMBOL: %c (ASCII: %d)\n", field[i][j], field[i][j]);
      if(field[i][j] == B) {
        amountB++;
      }else if(field[i][j] == '\0') {
        break;
      }
    }
    printf("END...\n");
  } 
  return amountB;
}

int main() {
  int n, totalB;
  if(scanf("%d", &n) != 1) return 1;

  if(n> maxL -1) {
    printf("Very big N...");
    return 1;
  }

  char field[maxL][maxL];
  for(int i = 0; i<n; i++) {
    scanf("%100s", field[i]);
    
  }

  totalB = getBlackAmount(n, field);

  printf("%d\n", totalB);
  return 0;
}
