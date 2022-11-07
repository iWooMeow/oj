#include <stdio.h>

int Ants(int n);

int main() {
  int n = 0;
  scanf("%d", &n);
  printf("%d", Ants(n));
  return 0;
}

int Ants(int n) {
  if (n == 1) {
    return 1;
  } else if (n == 0) {
    return 1;
  } else {
    return Ants(n - 1) + Ants(n - 2);
  }
}
