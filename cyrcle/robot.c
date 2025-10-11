#include <stdio.h>

int main() {
  int l, k, s, totalSteps;

  int restDist;
  int step = 0;
  int done = 0;

  scanf("%d%d%d", &s, &l, &k);

  step = l;
  done = step;
  totalSteps = 1;
  restDist = s;

  while (done < s && step < restDist) {
    step+=k;
    done +=step;
    totalSteps +=1;
    restDist = s - done;
  }

  printf("%d %d", totalSteps, restDist);

  return 0;
}