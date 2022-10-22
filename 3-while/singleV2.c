#include <stdio.h>

int main() {
  int array[10] = {0};
  for (int i = 0; i < 10; i++) {
    scanf("%d", &array[i]);
  }
  int result = 0;
  for (int i = 0; i < 32; i++) {
    int mask = 1 << i;
    int maskCount = 0;
    for (int j = 0; j < 10; j++) {
      if (array[j] & mask) {
        maskCount++;
      }
    }
    if (maskCount % 3) {
      result |= mask;
    }
  }
  printf("%d", result);
  return 0;
}
