#include <stdbool.h>
#include <stdio.h>

int midDetect(int array[], int mid);
bool valid(int array[], int midIndex);

int n = 0, k = 0;
int main() {
  scanf("%d%d", &n, &k);
  int array[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }
  int l = 0, r = n - 1;
  int mid = array[k - 1];
  for (; l != r;) {
    for (; array[l] < mid && l < r; l++) {
    }
    for (; array[r] >= mid && r > l; r--) {
    }
    if (l != r) {
      int temp = array[l];
      array[l] = array[r];
      array[r] = temp;
    } else {
      break;
    }
  }
  int midIndex = midDetect(array, mid);
  // if (valid(array, midIndex) == false) {
  int tempi = array[l];
  array[l] = mid;
  array[midIndex] = tempi;
  // }

  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}
int midDetect(int array[], int mid) {
  int index = 0;
  for (; array[index] != mid; index++)
    ;
  return index;
}
bool valid(int array[], int midIndex) {
  bool status = true;
  for (int i = 0; i < midIndex; i++) {
    if (array[i] >= array[midIndex]) {
      status = false;
      break;
    }
  }
  for (int i = midIndex + 1; i < n - 1; i++) {
    if (array[i] < array[midIndex]) {
      status = false;
      break;
    }
  }
  return status;
}
