#include <stdio.h>

int main() {
  int n, m, k;
  scanf("%d%d", &n, &m);
  int matrix[n][m];

  for(int i =0; i< n; i++) {
    for(int j = 0; j<m; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  scanf("%d", &k);

  for(int i= 0; i<n; i++) {
    for(int j = 0; j< m; j++) {
      matrix[i][j] *=k;
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}