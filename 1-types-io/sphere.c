#include <math.h>
#include <stdio.h>
int main() {
  int radius = 100;
  const double PI = 3.14159;
  double surfaceArea = 4 * PI * radius * radius;
  double volume = 4.0 / 3 * PI * pow(radius, 3);
  printf("%-15.4f : surfaceArea\n%-15.4f : volume\n", surfaceArea, volume);
  return 0;
}
