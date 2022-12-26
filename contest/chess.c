#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000005

int boardOrigin[N];
int boardUpdated[N];

int SearchNum(int array[], int length, int target);

int main() {
  int n = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &boardOrigin[i]);
  }
  int GameIndex = SearchNum(boardOrigin, n, 2);
  boardUpdated[GameIndex] = 1;
  // Move
  if (GameIndex - 1 >= 0 && boardOrigin[GameIndex - 1] == 0) {
    // printf("DEBUG:1\n");
    boardUpdated[GameIndex - 1] = 1;
  } else if (GameIndex - 1 > 0) {
    // printf("DEBUG:2\n");
    for (int i = GameIndex - 2; i >= 0; i -= 2) {
      if (boardOrigin[i + 1] == 1 && boardOrigin[i] == 0 &&
          boardUpdated[i + 2] == 1) {
        boardUpdated[i] = 1;
      }
    }
  }
  if (GameIndex + 1 < n && boardOrigin[GameIndex + 1] == 0) {
    // printf("DEBUG:3\n");
    boardUpdated[GameIndex + 1] = 1;
  } else if (GameIndex + 1 < n) {
    // printf("DEBUG:4\n");
    for (int i = GameIndex + 2; i < n; i += 2) {
      if (boardOrigin[i - 1] == 1 && boardOrigin[i] == 0 &&
          boardUpdated[i - 2] == 1) {
        boardUpdated[i] = 1;
      }
    }
  }
  // Print
  // boardUpdated[GameIndex] = 0;
  for (int i = 0; i < n; i++) {
    printf("%d ", boardUpdated[i]);
  }
  return 0;
}

int SearchNum(int array[], int length, int target) {
  for (int i = 0; i < length; i++) {
    if (boardOrigin[i] == target) {
      return i;
    }
  }
  return -1;
}
