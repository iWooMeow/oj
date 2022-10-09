#include <stdio.h>

void inverse(int a, int b, char array[]);

int main() {
  int n = 0, k = 0;
  scanf("%d", &n);
  char x;
  x=getchar();
  char array[n];
  for (int i = 0; i < n; i++) {
    scanf("%c", &array[i]);
  }
  scanf("%d", &k);
  if (k == 0) {
    inverse(k, n - 1, array);
  } else if (k == n) {
    inverse(0, n - 1, array);
  } else {
    inverse(0, k - 1, array);
    // for (int i = n - 1; i > k - 1; i--) {
    //   printf("%c", array[i]);
    // }
    inverse(k, n - 1, array);
  }
  return 0;
}

void inverse(int a, int b, char array[]) {
  for (int i = b; i >= a; i--) {
    printf("%c", array[i]);
  }
}
