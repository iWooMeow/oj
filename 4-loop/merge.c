#include <stdio.h>

int main() {
  int array1[] = {1, 2, 3, 5, 6};
  int array2[] = {1, 2, 2, 8, 8, 10};
  int l1 = 0;
  int l2 = 0;
  while (l1 < 5 && l2 < 6) {
    if (array1[l1] >= array2[l2]) {
      printf("%d ", array2[l2]);
      l2++;
    } else {
      printf("%d ", array1[l1]);
      l1++;
    }
  }
  while (l1 < 5) {
    printf("%d ", array1[l1]);
    l1++;
  }
  while (l2 < 6) {
    printf("%d ", array2[l2]);
    l2++;
  }
  return 0;
}
