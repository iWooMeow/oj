#include <stdio.h>

int main() {
  int radius = 10; // radius refers to a location &radius in memory(scanf use &)
  const double PI = 3.14159;
  double circumference = 2 * PI * radius;
  double area = PI * radius * radius;
  printf("circumference=%.2f\n", circumference);
  printf("area=%.2f\n", area);
  return 0;
}
