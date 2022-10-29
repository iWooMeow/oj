#include <stdio.h>
#define LEN 5

int BinarySearch(int key, int dict[], int len);

// avoid using global variables
// learn to add const when not modify the array

int main(void) {

  int key = 5;
  int dict[LEN] = {1, 3, 5, 6, 6};
  int index = BinarySearch(key, dict, LEN);
  printf("%d", index);
  return 0;
}

int BinarySearch(int key, int *dict, int len) {
  // int array[7] = {1, 2, 3, 7, 8, 90, 10000};
  // int target = 10000;
  // int index = -1;
  // printf("%#X\n", dict);
  int high = len - 1, low = 0;
  while (high >= low) {
    int mid = (high + low) / 2;
    if (dict[mid] > key) {
      high = mid - 1;
    } else if (dict[mid] < key) {
      low = mid + 1;
    } else {
      // index = mid;
      // high = index - 1;
      return mid;
      // break;
    }
  }

  return -1;
  // printf("%d", index);
  // return 0;
}
