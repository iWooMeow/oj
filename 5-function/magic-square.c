#include <stdio.h>

int square[1005][1005];

int main(void) {
  int n = 0;
  scanf("%d", &n);
  int row = 0;
  int col = n / 2;
  square[row][col] = 1;
  int colTmp = n / 2;
  int rowTmp = 0;
  int count = 2;
  for (int i = 0; i < n * n - 1; i++) {
    if (rowTmp - 1 < 0 && colTmp + 1 > n - 1) {
      rowTmp = n - 1;
      colTmp = 0;
    } else if (rowTmp - 1 < 0) {
      rowTmp = n - 1;
      colTmp += 1;
    } else if (colTmp + 1 > n - 1) {
      rowTmp -= 1;
      colTmp = 0;
    } else {
      rowTmp -= 1;
      colTmp += 1;
    }
    if (square[rowTmp][colTmp] != 0) {
      square[row + 1][col] = count++;
      row += 1;
      rowTmp = row;
      colTmp = col;
    } else {
      square[rowTmp][colTmp] = count++;
      row = rowTmp;
      col = colTmp;
    }
  }
  for (int row = 0; row < n; ++row) {
    for (int col = 0; col < n; col++) {
      printf("%d ", square[row][col]);
    }
    putchar('\n');
  }
  return 0;
}
