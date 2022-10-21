#include <stdio.h>

int joseRecur(int n, int k);
int joseIter(int n, int k);

int main() {
  int n = 0, k = 0;
  scanf("%d%d", &n, &k);
  int result = joseRecur(n, k);
  // int result = joseIter(n, k);
  printf("%d", result);
  return 0;
}
int joseRecur(int n, int k) {
  if (n == 1) {
    return 1;
  } else {
    return ((joseRecur(n - 1, k) - k - 1) % n + n) % n + 1;
  }
}
int joseIter(int n, int k) {
  int result = 1;
  for (int i = 2; i <= n; i++) {
    result = ((result - k - 1) % i + i) % i + 1;
  }
  return result;
}
