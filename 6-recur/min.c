#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM 100000

int Min(int len, const int num[]);

int main() {
  int numbers[NUM] = {1, 2, 5, 3, 2, 6, 0};
  int min = Min(NUM, numbers);
  printf("%d", min);
  return 0;
}

int Min(int len, const int num[]) {
  if (len == 1) {
    return num[0];
  } else {
    int tmp = Min(len - 1, num);
    return num[len - 1] > tmp ? tmp : num[len - 1];
  }
}
