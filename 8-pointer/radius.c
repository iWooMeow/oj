#include <stdio.h>

int main() {
  int radius = 5;
  int *ptr = &radius;
  printf("ptr:%p\n", &ptr);
  printf("ptr:%p\n", ptr);
  printf("ptr:%p\n", &radius);

  return 0;
}
