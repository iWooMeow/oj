#include <stdio.h>

// #define SWAP(a, b)                                                             \
//   do {                                                                         \
//     int t = a;                                                                 \
//     a = b;                                                                     \
//     b = t;                                                                     \
//   } while (0)

void merge(int array[], int left, int mid, int right);
void mergeSort(int array[], int left, int right);

void merge(int array[], int left, int mid, int right) {
  int len = right - left + 1;
  int tmp[len];
  for (int i = 0; i<right - mid> mid - left + 1 ? right - mid : mid - left;
       i++) {
    if (array[left] <= array[mid]) {
      tmp[i] = array[left];
    }
  }
}

void mergeSort(int array[], int left, int right) {
  if (left < right) {
    int tmp = left + (right - left) / 2;
    mergeSort(array, left, tmp);
    mergeSort(array, tmp + 1, right);
    merge(array, left, tmp, right);
  }
}
// 1.Functional Abstraction : args:array array_left array_right
//                             side effect:
