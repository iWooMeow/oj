#include <stdio.h>

int main() {
  int n = 0;
  scanf("%d", &n);
  // int array[n];
  // for (int i = 0; i < n; i++) {
  //
  //   scanf("%d", &array[i]);
  // }
  int ans = 0, num;
  for (int i = 0; i < 2 * n - 1; i++) {
    scanf("%d", &num);
    ans ^= num;
  }
  printf("%d", ans);
  return 0;
}
