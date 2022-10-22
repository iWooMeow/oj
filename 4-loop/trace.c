#include <stdbool.h>
#include <stdio.h>

int coordrow[2500];
int coordcol[2500];
char board[500][500];
char boardo[500][500];
bool valid[500][500];
int main() {
  int n = 0;
  int m = 0;
  int startrow = 0;
  int startcol = 0;
  int count = 0;
  scanf("%d%d%d%d", &n, &m, &startrow, &startcol);
  getchar();
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      scanf("%c", &boardo[row][col]);
    }
    getchar();
  }
  for (int col = 0; col <= m + 1; col++) {
    for (int row = 0; row <= n + 1; row++) {
      if (row == 0 || row == n + 1 || col == 0 || col == m + 1) {
        board[row][col] = '_';
      } else {
        board[row][col] = boardo[row - 1][col - 1];
      }
    }
  }
  // for (int row = 0; row <= m + 1; row++) {
  //   for (int col = 0; col <= n + 1; col++) {
  //     printf("%c", board[row][col]);
  //   }
  //   printf("\n");
  // }
  for (int row = 0; row <= n + 1; row++) {
    for (int col = 0; col <= m + 1; col++) {
      valid[row][col] = false;
    }
  }
  valid[startrow][startcol] = true;
  int row = startrow, col = startcol;
  coordrow[0] = startrow;
  coordcol[0] = startcol;

  for (;;) {
    if (board[row - 1][col] == '#' && valid[row - 1][col] == false) {
      row--;
      count++;
      valid[row][col] = true;
      coordrow[count] = row;
      coordcol[count] = col;
    } else if (board[row][col - 1] == '#' && valid[row][col - 1] == false) {
      col--;
      count++;
      valid[row][col] = true;
      coordrow[count] = row;
      coordcol[count] = col;
    } else if (board[row][col + 1] == '#' && valid[row][col + 1] == false) {
      col++;
      count++;
      valid[row][col] = true;
      coordrow[count] = row;
      coordcol[count] = col;
    } else if (board[row + 1][col] == '#' && valid[row + 1][col] == false) {
      row++;
      count++;
      valid[row][col] = true;
      coordrow[count] = row;
      coordcol[count] = col;
    } else {
      break;
    }
  }
  printf("%d", count + 1);
  printf("\n");
  for (int i = 0; i <= count; i++) {
    printf("%d %d", coordrow[i], coordcol[i]);
    printf("\n");
  }
  return 0;
}
