#include <math.h>
#include <stdio.h>

char board[2050][2050];

void paintTri(int x, int y);
// void paintSpace(int x, int y);
void paint(int n, int x, int y);

int main() {
  int n;
  scanf("%d", &n);
  // paintTri(1, 0, 500);
  // paintSpace(0, 500 - 2);
  // paintTri(1, 2, 500 - 2);
  paint(n, 0, 1025);
  for (int row = 0; row < pow(2, n); row++) {
    for (int col = 1025; col < pow(2,n) + 1025; col++) {
      if (board[row][col] == 0)
        board[row][col] = ' ';
    }
    for (int col = 1025; col > -pow(2,n) + 1025; col--) {
      if (board[row][col] == 0)
        board[row][col] = ' ';
    }
  }
  for (int row = 0; row < pow(2, n); row++) {
    for (int col = 0; col < 2050; col++) {
      printf("%c", board[row][col]);
    }
    printf("\n");
  }

  return 0;
}

void paintTri(int x, int y) {
  board[x][y - 1] = ' ';
  board[x][y] = '/';
  board[x][y + 1] = '\\';
  // board[x][y + 2] = '\n';
  board[x + 1][y - 1] = '/';
  board[x + 1][y + 2] = '\\';
  // board[x + 1][y + 3] = '\n';
  board[x + 1][y] = '_';
  board[x + 1][y + 1] = '_';
}
// void paintSpace(int x, int y) {
//   for (int row = 0; row < 2; row++) {
//     for (int col = 0; col < 2; col++) {
//       board[x + row][y + col] = ' ';
//     }
//   }
// }

void paint(int n, int x, int y) {
  // 2      0     1025
  if (n == 1) {
    paintTri(x, y);
    // 0 1025
  } else {
    paint(n - 1, x, y);
    // 1    0   1025

    // for (int i = 0; i < pow(2, n-1); i++) {
    //   // paintspace(i, y + 1 - pow(2, n - 1) - 2);
    //   int count = 0;
    //   for (int j = y - pow(2, n); count <= pow(2, n-1); count++) {
    //
    //     board[i][j] = ' ';
    //     j--;
    //   }
    //   // 2
    // }
    // paint(n - 1, pow(2, n - 1), y + 1 - pow(2, n - 1));
    paint(n - 1, x + pow(2, n - 1), y - pow(2, n - 1));
    paint(n - 1, x + pow(2, n - 1), y + pow(2, n - 1));
    // 1              2               2
    // paint(n - 1, pow(2, n - 1), y + pow(2, n - 1));
  }
}
/*
   /\
  /__\
 /\  /\
/__\/__\
*/
