#include <stdio.h>

int poi(int n, const int criminal[]);

int criminal[100005];

int main() {
  int n = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &criminal[i]);
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", poi(i, criminal));
  }
  return 0;
}

int poi(int n, const int criminal[]) {
  if (n == criminal[n]) {
    return n;
  } else {
    return poi(criminal[n], criminal);
  }
}
