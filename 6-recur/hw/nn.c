#include <math.h>
#include <stdio.h>

char board[2050][2050];

void paintTri(int x, int y);
void paint(int n, int x, int y);

int main() {
  int n;
  scanf("%d", &n);
  paint(n, 0, 1025);
  for (int row = 0; row < pow(2, n); row++) {
    for (int col = 1025; col < row + 1025; col ++) {
      if (board[row][col] == 0)
        board[row][col] = ' ';
    }
    for (int col = 1025; col > -pow(2, n) + 1025; col--) {
      if (board[row][col] == 0)
        board[row][col] = ' ';
    }
  }
  for (int row = 0; row < pow(2, n); row++) {
    for (int col = 0; col < 2050; col++) {
      if (board[row][col] != 0) {
        printf("%c", board[row][col]);
      }
    }
    printf("\n");
  }
  return 0;
}
void paintTri(int x, int y) {
  board[x][y - 1] = ' ';
  board[x][y] = '/';
  board[x][y + 1] = '\\';
  board[x + 1][y - 1] = '/';
  board[x + 1][y + 2] = '\\';
  board[x + 1][y] = '_';
  board[x + 1][y + 1] = '_';
}
void paint(int n, int x, int y) {
  if (n == 1) {
    paintTri(x, y);
  } else {
    paint(n - 1, x, y);
    paint(n - 1, x + pow(2, n - 1), y - pow(2, n - 1));
    paint(n - 1, x + pow(2, n - 1), y + pow(2, n - 1));
  }
}
