#include <stdio.h>

int main() {
  long double x = 0, result = 0;
  int n = 0;
  scanf("%Lf%d", &x, &n);
  long double temp = 4 * x;
  for (int i = 0; i <= n; i++) {
    result += temp / (2 * i + 1);
    temp = temp * x * x * (-1);
  }
  printf("%.10Lf", result);
  return 0;
}
