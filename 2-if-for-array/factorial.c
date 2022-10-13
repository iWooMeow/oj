#include <stdio.h>
#define DIVISOR 10007

int main() {
  int n = 0, result = 0, temp = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    temp = (temp * i) % DIVISOR;
    result = (result + temp) % DIVISOR;
  }
  printf("%d", result);
  return 0;
}
