#include <stdio.h>
#define LEN 5

int BinarySearch(int key, int dict[], int len);
int BinaryRecur(int key, const int dict[], int left, int right);

// avoid using global variables
// learn to add const when not modify the array

int main(void) {

  int key = 7;
  scanf("%d", &key);
  int dict[LEN] = {1, 3, 5, 6, 99};
  int index = BinaryRecur(key, dict, 0, LEN);
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
int BinaryRecur(int key, const int dict[], int left, int right) {

  // int index = -1;
  int mid = (right + left) / 2;
  if (left < right && dict[mid] == key) {
    return mid;
  } else if (left == right) {
    return -1;
  } else {
    left = dict[mid] > key ? left : mid + 1;
    right = dict[mid] < key ? right : mid;
    return BinaryRecur(key, dict, left, right);
  }
}
