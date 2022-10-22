#include <stdio.h>

// o==111,*=42
int main() {
  int size = 0;
  scanf("%d", &size);
  getchar();
  char board0[size][size];
  char board[size + 2][size + 2];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      scanf("%c", &board0[i][j]);
    }
    getchar();
  }
  for (int i = 0; i <= size + 1; i++) {
    for (int j = 0; j <= size + 1; j++) {
      if (i == 0 || j == 0 || i == size + 1 || j == size + 1) {
        board[i][j] = 'o';
      } else {
        board[i][j] = board0[i - 1][j - 1];
      }
    }
  }
  for (int row = 1; row <= size; row++) {
    for (int col = 1; col <= size; col++) {
      int valid = board[row - 1][col] + board[row - 1][col + 1] +
                  board[row - 1][col - 1] + board[row + 1][col] +
                  board[row + 1][col + 1] + board[row + 1][col - 1] +
                  board[row][col + 1] + board[row][col - 1];
      if (board[row][col] == 42) {
        board0[row - 1][col - 1] = '*';
      } else {
        board0[row - 1][col - 1] = (888 - valid) / 69 + '0';
      }
    }
  }
  // for (int row = 0; row < size + 2; row++) {
  //   for (int col = 0; col < size + 2; col++) {
  //     printf("%c", board[row][col]);
  //   }
  //   printf("\n");
  // }
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      printf("%c", board0[row][col]);
    }
    printf("\n");
  }
  return 0;
}
