#include <stdio.h>

int main() {
  int array[10] = {0};
  for (int i = 0; i < 10; i++) {
    scanf("%d", &array[i]);
  }
  int tmp = 0;
  for (int i = 0; i < 10; i++) {
    tmp ^= array[i];
  }
  int mask = 1;
  int a = 0, b = 0;
  for (int i = 0; i < 32; i++) {
    mask <<= 1;
    if (tmp & mask) {
      break;
    }
  }
  for (int i = 0; i < 10; i++) {
    if (array[i] & mask) {
      a ^= array[i];
    } else {
      b ^= array[i];
    }
  }
  printf("%d %d", a, b);
  return 0;
}
