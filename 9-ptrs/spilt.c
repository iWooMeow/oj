#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// void QuickSortPit(char **array, int left, int right);
int cmp(const void *a, const void *b);

int main() {
  char *buf = (char *)malloc(sizeof(char) * 1000);
  char *delimiter = (char *)malloc(sizeof(char) * 3);
  scanf("%s%s", buf, delimiter);
  char *ptr = strtok(buf, delimiter);
  char **output = (char **)malloc(sizeof(char *) * 1000);
  int cnt = 0;
  while (ptr != NULL) {
    *(output + cnt++) = ptr;
    ptr = strtok(NULL, delimiter);
  }
  // QuickSortPit(output, 0, cnt - 1);
  qsort(output, cnt, sizeof(char *), cmp);
  for (int i = 0; i < cnt; i++) {
    printf("%s\n", *(output + i));
  }
  return 0;
}

int cmp(const void *a, const void *b) {
  printf("DEBUG:%d\n", strcmp(a, b));
  // return strcmp(a, b);
  return strcmp(*(char **)a, *(char **)b);
}

// void QuickSortPit(char **array, int left, int right) {
//   if (left >= right) {
//     return;
//   } else {
//     char *pivot = *(array + left);
//     int leftCnt = left;
//     int rightCnt = right;
//     while (leftCnt < rightCnt) {
//       while (strcmp(*(array + rightCnt), pivot) >= 0 && leftCnt < rightCnt) {
//         rightCnt--;
//       }
//       *(array + leftCnt) = *(array + rightCnt);
//       while (strcmp(*(array + leftCnt), pivot) <= 0 && leftCnt < rightCnt) {
//         leftCnt++;
//       }
//       *(array + rightCnt) = *(array + leftCnt);
//     }
//     *(array + leftCnt) = pivot;
//     QuickSortPit(array, left, leftCnt - 1);
//     QuickSortPit(array, leftCnt + 1, right);
//   }
// }
