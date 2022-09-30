#include <math.h>
#include <stdio.h>

int main() {
  int p, q;
  double result;
  scanf("%d%d", &p, &q);
  result = cbrt(-0.5 * q + sqrt(pow(q / 2.0, 2) + pow(p / 3.0, 3))) +
           cbrt(-0.5 * q - sqrt(pow(q / 2.0, 2) + pow(p / 3.0, 3)));
  printf("%.3f", result);
  return 0;
}
