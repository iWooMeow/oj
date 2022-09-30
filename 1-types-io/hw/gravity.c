#include <stdio.h>

int main() {
  const double G = 6.674e-11;
  const double M = 77.15;
  double mass, radius;
  scanf("%le%le", &mass, &radius);
  double gravity;
  gravity = G * mass * M / (radius * radius);
  printf("%.4g", gravity);

  return 0;
}
