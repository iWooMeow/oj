#include <stdio.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

char next[1001];
char life[1001];

int main(int argc, char *argv[]) {
  int round;
  scanf("%d%s", &round, life);
  int len = strlen(life);
  while (round--) {
    memset(next, '.', 1000);
    for (int i = 0; i < len; i++) {
      int cntA = 0, cntB = 0;
      for (int j = max(i - 3, 0); j < min(i + 4, len); j++) {
        if (j == i)
          continue;
        if (life[j] == 'A')
          cntA++;
        if (life[j] == 'B')
          cntB++;
      }
      next[i] = life[i];
      if (life[i] == 'A' && (cntB || (cntA <= 1 || cntA >= 5)))
        next[i] = '.';
      if (life[i] == 'B' && (cntA || (cntB <= 1 || cntB >= 5)))
        next[i] = '.';
      if (life[i] == '.' && cntA >= 2 && cntA <= 4 && !cntB)
        next[i] = 'A';
      if (life[i] == '.' && cntB >= 2 && cntB <= 4 && !cntA)
        next[i] = 'B';
    }
    strncpy(life, next, len);
  }
  puts(life);
  return 0;
}
