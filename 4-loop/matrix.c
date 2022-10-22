#include <stdio.h>

int matrixA[100][100];
int matrixB[100][100];

int main() {
  int m = 0, n = 0, p = 0;
  scanf("%d%d%d", &m, &n, &p);
  for (int row = 0; row < m; row++) {
    for (int col = 0; col < n; col++) {
      scanf("%d", &matrixA[row][col]);
    }
  }
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < p; col++) {
      scanf("%d", &matrixB[row][col]);
    }
  }
  for (int row = 0; row < m; row++) {
    for (int col = 0; col < p; col++) {
      int ans = 0;
      for (int num = 0; num < n; num++) {
        ans += matrixA[row][num] * matrixB[num][col];
      }
      printf("%d ", ans);
    }
    printf("\n");
  }
  return 0;
}
