#include <stdbool.h>
#include <stdio.h>

int validate[9] = {0};
bool valid(int validate[]);

int main() {
  int sudo[9][9];
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      scanf("%d", &sudo[row][col]);
      if (sudo[row][col] > 9) {
        printf("NO");
        return 0;
      }
    }
  }
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      validate[col] = sudo[row][col];
    }
    if (!valid(validate)) {
      printf("NO");
      return 0;
    }
  }
  for (int col = 0; col < 9; col++) {
    for (int row = 0; row < 9; row++) {
      validate[row] = sudo[row][col];
    }
    if (!valid(validate)) {
      printf("NO");
      return 0;
    }
  }
  for (int i = 1; i < 7; i += 3) {
    for (int j = 1; j < 7; j += 3) {
      int special[] = {
          sudo[i][j],         sudo[i - 1][j + 1], sudo[i - 1][j],
          sudo[i - 1][j - 1], sudo[i][j - 1],     sudo[i][j + 1],
          sudo[i + 1][j - 1], sudo[i + 1][j],     sudo[i + 1][j + 1]};
      if (valid(special) == false) {
        printf("NO");
        return 0;
      }
    }
  }
  printf("YES");
  return 0;
}
bool valid(int validate[]) {
  // int status = 0;
  // for (int i = 1; i <= 9; i++) {
  //   for (int j = 0; j < 9; j++) {
  //     if (validate[j] == i) {
  //       status++;
  //       break;
  //     }
  //   }
  // }
  // if (status != 9) {
  //   return false;
  // } else {
  //   return true;
  // }
  int bucket[100] = {0};
  for (int i = 0; i < 9; i++) {
    bucket[validate[i]]++;
  }
  for (int i = 1; i <= 9; i++) {
    if (bucket[i] != 1) {
      return false;
    }
  }
  return true;
}
// remember to break the loop
