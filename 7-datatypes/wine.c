#include <stdio.h>

// #define MAX(a, b) ((a) > (b) ? (a) : (b))

int value[10005];
int max[10005];
int added[10005];

int MaxValue(int n, int l, int value[], int max[]);
int MaxIndex(int num[], int len);

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

int MaxValue(int n, int l, int value[], int max[]) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int maxIndice = MaxIndex(value, n);
    if (l == 0)
      break;
    if (max[maxIndice] <= l) {
      l -= max[maxIndice];
      ans += max[maxIndice] * value[maxIndice];
      value[maxIndice] = 0;
      max[maxIndice] = 0;
    } else {
      ans += value[maxIndice] * l;
      l = 0;
      break;
    }
  }
  return ans;
}

int MaxIndex(int num[], int len) {
  int ansIndex = 1;
  for (int i = 1; i <= len; i++) {
    if (num[i] > num[ansIndex]) {
      ansIndex = i;
    }
  }
  return ansIndex;
}
