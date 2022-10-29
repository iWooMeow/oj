#include <stdbool.h>
#include <stdio.h>

bool PrimeJudge(int x);
int flip(int input);

int main(void) {
  int n, count = 0;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int tmp = flip(i);
    if (PrimeJudge(tmp) && PrimeJudge(i)) {
      count++;
    }
  }
  printf("%d",count);
  return 0;
}

bool PrimeJudge(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int flip(int input) {
  int ans = 0;
  if (input == 1000) {
    ans = 1;
  } else if (input < 10) {
    ans = input;
  } else if (input < 100) {
    ans = input % 10 * 10 + input / 10;
  } else if (input < 1000) {
    ans = input % 10 * 100 + input / 100 +
          (input - input / 100 * 100 - input % 10);
  }
  return ans;
}
