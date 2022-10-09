#include <stdbool.h>
#include <stdio.h>

int main() {
  int n = 0;
  scanf("%d", &n);
  int array[n * 10];
  int num = 0;
  for (int i = 0; i < 10 * n; i++) {
    array[i] = 0;
  }
  for (int i = 1; i <= 2 * n - 1; i++) {
    scanf("%d", &num);
    array[num] = 1 - array[num];
  }
  for (int i = 1; i < 10 * n; i++) {
    if (array[i] == 1) {
      printf("%d", i);
    }
  }
  return 0;
}
