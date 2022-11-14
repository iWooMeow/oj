#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int value[10005];
int max[10005];

int MaxValue(int n, int l, const int value[], const int max[]);

int main() {
  int n, l;
  scanf("%d%d", &n, &l);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &value[i]);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &max[i]);
  }
  printf("%d", MaxValue(n, l, value, max));
  return 0;
}

int MaxValue(int n, int l, const int value[], const int max[]) {
  int ans = 0;
  if (l == 0) {
    return 0;
  } else {
    for (int i = 1; i <= n; i++) {
      int added[10005];
      if (added[i] < max[i]) {
        ans = MAX(ans, MaxValue(n, l - 1, value, max) + value[i]);
        added[i]++;
      } else {
        i++;
      }
    }
    return ans;
  }
}
