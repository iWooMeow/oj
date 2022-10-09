#include <stdio.h>
#include <stdlib.h>
int main() {
  int a, b, c, d, e, f;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  if (((a == c) && (a < e) && (e < c)) || ((a == c) && (a > e) && (e > c))) {

    printf("%d\n", abs(b - d) + 2);

  } else if (((b == d) && (b < f) && (f < d)) ||
             ((b == d) && (b > f) && (f > d))) {
    printf("%d\n", abs(a - c) + 2);
  } else {
    printf("%d\n", abs(a - c) + abs(b - d));
  }
  return 0;
}
