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

  while (done < s && step -k <= restDist && step -k > 0) {
    step-=k;
    done +=step;
    totalSteps +=1;
    restDist = s - done;
    printf("step: %d, rest: %d, s: %d\n", step, restDist, step<restDist);
  }

  printf("%d %d", totalSteps, restDist);

  return 0;
}