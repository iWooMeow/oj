#include <math.h>
#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)

int outputAsDecemal(int x, int base);
int baseJudge(int x);

int main(void) {
  int p, q, r;
  scanf("%d%d%d", &p, &q, &r);
  int baseMin = MAX(baseJudge(r), MAX(baseJudge(p), baseJudge(q)));
  for (int i = baseMin + 1; i <= 40; i++) {
    int pp = outputAsDecemal(p, i);
    int qq = outputAsDecemal(q, i);
    int rr = outputAsDecemal(r, i);
    if (pp * qq == rr) {
      printf("%d", i);
      return 0;
    }
  }
  printf("0");

  return 0;
}

int baseJudge(int x) {
  int base = 2;
  while (x > 0) {
    base = MAX(base, x % 10);
    x /= 10;
  }
  return base;
}

int outputAsDecemal(int x, int base) {
  int ans = 0;
  for (int i = 0; x > 0; i++) {
    ans += x % 10 * pow(base, i);
    x /= 10;
  }
  return ans;
}
