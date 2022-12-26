#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char board[5][9];

int Precondition(void);
int Advance(int row, int col);
int Back(int row, int col);
int Right(int row, int col);
int Left(int row, int col);
int Judge(void);

int main() {
  int T = 0;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    for (int row = 0; row < 5; row++) {
      scanf("%s", board[row]);
    }
    if (Precondition()) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}

int Precondition(void) {
  int indexKingCol = 0;
  int indexKingRow = 0;
  for (int row = 0; row < 5; row++) {
    if (strchr(board[row], 'k') != NULL) {
      indexKingCol = strchr(board[row], 'k') - board[row];
      indexKingRow = row;
      break;
    }
  }
  int soldierCnt = 0;
  int SoldierCol[5] = {0};
  int SoldierRow[5] = {0};
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 9; col++) {
      if (board[row][col] == 's') {
        SoldierCol[soldierCnt] = col;
        SoldierRow[soldierCnt] = row;
        soldierCnt++;
      }
    }
  }
  for (int i = 0; i < soldierCnt; i++) {
    if (Advance(SoldierRow[i], SoldierCol[i]) == 1) {
      if ()
        SoldierRow[i]++;
      Back(SoldierRow[i], SoldierCol[i]);
    }
  }
  return 0;
}

int Judge(void) {
  int indexKingCol = 0;
  int indexKingRow = 0;
  for (int row = 0; row < 5; row++) {
    if (strchr(board[row], 'k') != NULL) {
      indexKingCol = strchr(board[row], 'k') - board[row];
      indexKingRow = row;
      break;
    }
  }
  int soldierCnt = 0;
  int SoldierCol[5] = {0};
  int SoldierRow[5] = {0};
  for (int row = 0; row < 5; row++) {
    for (int col = 0; col < 9; col++) {
      if (board[row][col] == 's') {
        SoldierCol[soldierCnt] = col;
        SoldierRow[soldierCnt] = row;
        soldierCnt++;
      }
    }
  }
  if (indexKingCol ==3)
}

int Advance(int row, int col) {
  if (row + 1 < 5 && board[row + 1][col] == '#') {
    board[row + 1][col] = board[row][col];
    board[row][col] = '#';
    return 1;
  }
  return 0;
}
int Back(int row, int col) {
  if (row - 1 >= 0 && board[row - 1][col] == '#') {
    board[row - 1][col] = board[row][col];
    board[row][col] = '#';
    return 1;
  }
  return 0;
}
int Right(int row, int col) {
  if (col + 1 < 9 && board[row][col + 1] == '#') {
    board[row][col + 1] = board[row][col];
    board[row][col] = '#';
    return 1;
  }
  return 0;
}
int Left(int row, int col) {
  if (col - 1 >= 0 && board[row][col - 1] == '#') {
    board[row][col - 1] = board[row][col];
    board[row][col] = '#';
    return 1;
  }
  return 0;
}
