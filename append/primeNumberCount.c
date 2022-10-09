#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int primeIndex[100000000] = {3, 5};
int primeJudge(int n);
int primeJudgeBig(int n);
int primeCount(int input);
int main() {
  int input = 0;
  scanf("%d", &input);
  printf("%d", primeCount(input));
  return 0;
}

int primeCount(input) {
  int primeCount = 0;
  int i = 0;
  int times = 2;
  for (i = 2; i <= input; i++) {
    if (primeJudge(i)) {
      primeCount++;
      primeIndex[times] = i;
      times++;
    }
  }
  return primeCount;
}
int primeJudge(n) {
  bool Judge = 1;
  if (n == 2)
    Judge = 1;
  else if (n == 3)
    Judge = 1;
  else if (n == 4)
    Judge = 0;
  else if (n == 5)
    Judge = 1;
  else if (n == 6)
    Judge = 0;
  else if (n % 6 == 1 || n % 6 == 5)
    Judge = primeJudgeBig(n);
  else
    Judge = 0;
  return Judge;
}
int primeJudgeBig(n) {
  bool Judge = 1;
  int i;
  for (i = 0; primeIndex[i] <= sqrt(n); i++)
    if (n / primeIndex[i] * primeIndex[i] == n)
      Judge = 0;
  return Judge;
}
