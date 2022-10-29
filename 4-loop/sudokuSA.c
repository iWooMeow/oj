#include <stdio.h>

int sudoku[9][9], row[9][10], col[9][10], sub[9][10];
// 10 is board index 9 is bucket cnt
int i, j;
int main() {
  for (i = 0; i < 9; i++)
    for (j = 0; j < 9; j++) {
      scanf("%d", &sudoku[i][j]);
      if (sudoku[i][j] > 9 || sudoku[i][j] < 1) {
        printf("NO");
        return 0;
      }
      row[i][sudoku[i][j]]++;
      col[j][sudoku[i][j]]++;
      sub[i / 3 * 3 + j / 3][sudoku[i][j]]++;
    }
  for (i = 0; i < 9; i++) {
    for (j = 1; j < 10; j++) {
      if (row[i][j] != 1 || col[i][j] != 1 || sub[i][j] != 1) {
        printf("NO");
        return 0;
      }
    }
  }
  printf("YES");
  return 0;
}
