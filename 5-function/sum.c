#include <math.h>
#include <stdio.h>

int main(void) {
  int n, t, result = 0;
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; i++) {
    int tmp = 0;
    for (int j = 0; j <= i; j++) {
      tmp += t * pow(10, j);
    }
    result += tmp;
  }
  printf("%d", result);
  return 0;
}
