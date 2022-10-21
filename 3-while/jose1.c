#include <math.h>
#include <stdio.h>

int main() {
  int n = 0, k = 0;
  scanf("%d%d", &n, &k);
  if (fmod(log(n) / log(2), 1) == 0) {
    printf("1");
  }else
  return 0;
}
