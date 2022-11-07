#include <stdio.h>

int interval[100005];
int ans[100005][2];

// int maxseg(int n);

int main() {
  int n = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &interval[i]);
  }
  for (int i = 1; i <= n; i++) {
    int tmp = interval[i];
    for (int j = i; j >= 1; j--) {
      if (interval[j] <= tmp) {
        ans[i][0] = j;
      } else {
        break;
      }
    }
    for (int j = i; j <= n; j++) {
      if (interval[j] <= tmp) {
        ans[i][1] = j;
      } else {
        break;
      }
    }

  }
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", ans[i][0], ans[i][1]);
  }
  return 0;
}
