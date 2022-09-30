#include <stdio.h>

int main() {
  const int molOxygen = 32;
  int weight = 6;
  const double NA = 6.02e23;
  double quantity = weight * 1.0 / molOxygen * NA;
  printf("quantity=%.3e\nmass=%.5g\n", quantity, weight);
  return 0;
}
