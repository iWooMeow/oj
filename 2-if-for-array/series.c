#include <stdio.h>

int main() {
  double x = 0, result = 0;


  int n = 0;
  scanf("%lf%d", &x, &n);
  double temp = x;
  for (int i = 0; i <= n;) {
    result += temp;
    i++;
    temp *= x * x * (2 * i - 1) / (2 * i + 1) * (-1);
  }

  printf("%.10lf\n", 4 * result);
  return 0;
}
