#include <math.h>
#include <stdio.h>
int main() {
  double pidiv4;
  double pi;
  pidiv4 = 4 * atan(0.2) - atan(1.0 / 239);
  pi = log(pow(640320, 3) + 744) / sqrt(163);
  printf("%.15f\n%.15f", pidiv4, pi);
  return 0;
}
