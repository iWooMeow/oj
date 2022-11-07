#include <stdio.h>

int gcd(int a, int b);

int main() {
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d", gcd(a, b));
  return 0;
}

int gcd(int a, int b) {
  int ans = 1;
  if (a == 0) {
    return b;
  } else {
    return gcd(b % a, a);
  }
  return ans;
}
