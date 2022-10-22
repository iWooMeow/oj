#include <stdio.h>

int main() {
  int array[10] = {0};
  for (int i = 0; i < 10; i++) {
    scanf("%d", &array[i]);
  }
  for (int n = 9; n > 0; n--) {
    for (int i = 0; i < n; i++) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}
