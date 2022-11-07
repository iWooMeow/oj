#include <stdio.h>

int cal(int row, int col);

int main() {
  int row, col;
  scanf("%d%d", &row, &col);
  printf("%d", cal(row, col));
  return 0;
}

int cal(int row, int col) {
  if (col == 1 || row == 1 || row == col) {
    return 1;
  } else {
    return cal(row - 1, col) + cal(row - 1, col - 1);
  }
}
