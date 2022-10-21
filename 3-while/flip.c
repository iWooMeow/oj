#include <stdbool.h>
#include <stdio.h>

int main() {
  int n = 0;
  scanf("%d", &n);
  bool array[n];
  for (int i = 0; i < n; i++) {
    array[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int factor = 1; factor * i <= n; factor++) {
      array[factor * i - 1] = 1 - array[factor * i - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (array[i - 1] == 1) {
      printf("%d ", i);
    }
  }
  return 0;
}
