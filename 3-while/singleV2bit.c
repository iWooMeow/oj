#include <stdio.h>

int main() {
  int array[10] = {0};
  int one = 0, two = 0, three = 0;
  for (int i = 0; i < 10; i++) {
    scanf("%d", &array[i]);
  }
  for (int i = 0; i < 10; i++) {
    two |= one & array[i];
    one ^= array[i];
    three = one & two;
    one &= ~three;
    two &= ~three;
  }
  printf("%d", one);
  printf("%d", two);
  printf("%d", three);
  return 0;
}
