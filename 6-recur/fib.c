#include <stdio.h>

long long Fib(int n);
long long FibIter(int n);

int main() {
  int n = 0;
  scanf("%d", &n);
  long long ans = Fib(n);
  printf("%lld", ans);
  return 0;
}

long long Fib(int n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return Fib(n - 1) + Fib(n-2);
  }
}

long long FibIter(int n) {
  long long ans = 0;
  long long fib0 = 0, fib1 = 1;
  for (int i=0;i<=n;i++){
    ans = fib0 + fib1;
    fib0=fib1;
    fib1=ans;
  }
  return ans;
}
