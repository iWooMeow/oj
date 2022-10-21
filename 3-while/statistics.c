#include <stdio.h>

int count[123] = {0};
int backup[123] = {0};
int incorperation[26] = {0};

int max(int array[]);

int main() {
  int n = 0;
  char ascii = 0;
  scanf("%d", &n);
  getchar();
  // read input as ascii into count
  for (int i = 0; i < n; i++) {
    scanf("%c", &ascii);
    count[(int)ascii]++;
    backup[(int)ascii]++;
  }
  // incorperate the count for caps and non-caps
  // for (int i = 65; i <= 90; i++) {
  //   incorperation[i - 65] = count[i] + count[i + 32];
  // }
  int lines = max(count);
  for (int i = 1; i <= lines; lines--) {
    for (int i = 65; i <= 90; i++) {
      if (count[i] == lines && count[i + 32] == lines) {
        printf("== ");
        count[i]--;
        count[i + 32]--;
      } else if (count[i] == lines && count[i + 32] != 0) {
        printf(" = ");
        count[i]--;
      } else if (count[i] != 0 && count[i + 32] == lines) {
        printf("=  ");
        count[i + 32]--;
      } else if (count[i] == 0 && count[i + 32] == 0) {
      } else if (count[i] == 0 && count[i + 32] == lines) {
        printf("= ");
        count[i + 32]--;
      } else if (count[i] == lines && count[i + 32] == 0) {
        printf("= ");
        count[i]--;
      } else if ((count[i] == 0 && count[i + 32] != 0) ||
                 (count[i] != 0 && count[i + 32] == 0)) {
        printf("  ");
      } else if ((count[i] != 0 && count[i + 32] != 0)) {
        printf("   ");
      }
    }
    printf("\n");
  }
  int times = 0;
  for (int i = 65; i <= 90; i++) {
    if (backup[i] != 0 && backup[i + 32] != 0) {
      times += 3;
    } else if (backup[i] != 0) {
      times += 2;
    } else if (backup[i + 32] != 0) {
      times += 2;
    }
  }
  times--;

  for (int i = 0; i < times; i++) {
    printf("-");
  }
  printf("\n");
  for (int i = 65; i <= 90; i++) {
    if (backup[i] != 0 && backup[i + 32] != 0) {
      printf("%c%c ", i + 32, i);
    } else if (backup[i] != 0) {
      printf("%c ", i);
    } else if (backup[i + 32] != 0) {
      printf("%c ", i + 32);
    }
  }
  return 0;
}

int max(int array[]) {
  int maxNum = array[0];
  for (int i = 0; i < 123; i++) {
    if (maxNum < array[i]) {
      maxNum = array[i];
    }
  }
  return maxNum;
}

// 1.char count incorperation
// 2.sort decreasingly
// 3.print to corresponding position
// top line if (0,n) print " ",if =n print =,else print '';
