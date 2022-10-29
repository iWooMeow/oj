#include <stdio.h>

char c[105][105];
int sum[105][105];
int x;
int i, j;

int main() {
  scanf("%d\n", &x);
  for (i = 1; i <= x; i++)
    for (j = 1; j <= x + 1; j++) {
      scanf("%c", &c[i][j]);
      if (c[i][j] == '*') {
        sum[i][j] -= 9;
        sum[i - 1][j - 1]++;
        sum[i - 1][j]++;
        sum[i - 1][j + 1]++;
        sum[i][j - 1]++;
        sum[i][j + 1]++;
        sum[i + 1][j - 1]++;
        sum[i + 1][j]++;
        sum[i + 1][j + 1]++;
      }
    }
  for (i = 1; i <= x; i++) {
    for (j = 1; j <= x; j++)
      if (sum[i][j] >= 0)
        printf("%d", sum[i][j]);
      else
        printf("*");
    printf("\n");
  }
  return 0;
}
#include <stdio.h>
#define maxn 102
char map[maxn][maxn];
int n;
int directions[8][2] = {{0, 1},  {0, -1}, {1, 1},  {1, 0},
                        {1, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
int mineCounts[maxn][maxn] = {0};
int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%s", map[i]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (map[i][j] == '*')
        for (int k = 0; k < 8; k++) {
          int x = i + directions[k][0], y = j + directions[k][1];
          if (x >= 0 && y >= 0)
            mineCounts[x][y]++;
        }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%c", map[i][j] == '*' ? '*' : mineCounts[i][j] + '0');
    printf("\n");
  }
  return 0;
}
