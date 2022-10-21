#include <stdio.h>

int main() {
  int array[] = {1, 2, 7, 463, 763, 33, 88, 35};
  for (int i = 0; i < 7; i++) {
    int minIndex = i;
    for (int j = i; j < 8; j++) {
      if (array[minIndex] > array[j]) {
        minIndex = j;
      }
      int temp = array[minIndex];
      array[minIndex] = array[i];
      array[i] = temp;
    }
  }
  for (int i = 0; i < 8; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}
