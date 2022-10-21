#include <stdio.h>

int main() {
  int array[7] = {1, 2, 3, 7, 8, 90, 10000};
  int target = 10000;
  int index = -1;
  int high = 6, low = 0;
  while (high >= low) {
    int mid = (high + low) / 2;
    if (array[mid] > target) {
      high = mid - 1;
    } else if (array[mid] < target) {
      low = mid + 1;
    } else {
      index = mid;
      // high = index - 1;
      break;
    }
  }

  printf("%d", index);
  return 0;
}
