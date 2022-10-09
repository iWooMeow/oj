#include <stdio.h>

int max(int n, int m);

int main() {
  int input = 0;
  int m = 1;
  int i = 0;
  scanf("%d", &input);
  while (input > 1) {
    m = max(input, m);
    if (input % 2) {
      input = 3 * input + 1;
    } else {
      input /= 2;
    }
    i++;
  }
  printf("%d %d", i, m);
  return 0;
}
int max(int n, int m) {
  if (m < n) {
    return n;
  } else {
    return m;
  }
}
