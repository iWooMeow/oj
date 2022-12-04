#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int n = 0;
  return 0;
}
void MergeSortNonR(int *a, int n) {
  int *tmp = (int *)malloc(sizeof(int) * n);
  if (tmp == NULL) {
    perror("malloc failed");
    exit(-1);
  }
  int gap = 1;
  while (gap < n) {
    for (int j = 0; j < n; j += 2 * gap) {
      int begin1 = j;
      int end1 = j + gap - 1;
      int begin2 = j + gap;
      int end2 = j + 2 * gap - 1;
      if (end1 >= n) {
        break;
      }
      if (begin2 >= n) {
        break;
      }
      if (end2 >= n) {
        end2 = n - 1;
      }
      int i = j;
      while (begin1 <= end1 && begin2 <= end2) {
        if (a[begin1] <= a[begin2]) {
          tmp[i++] = a[begin1++];
        } else {
          tmp[i++] = a[begin2++];
        }
      }
      while (begin1 <= end1) {
        tmp[i++] = a[begin1++];
      }
      while (begin2 <= end2) {
        tmp[i++] = a[begin2++];
      }
      memcpy(a + j, tmp + j, sizeof(int) * (end2 - j + 1));
    }
    gap *= 2;
  }
  free(tmp);
  tmp = NULL;
}
