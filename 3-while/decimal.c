#include <math.h>
#include <stdio.h>

int main() {
  int len = 0, n = 0;
  scanf("%d%d", &len, &n);
  char num[len];
  getchar();
  for (int i = len - 1; i >= 0; i--) {
    scanf("%c", &num[i]);
  }
  // validate
  if (n <= 10) {
    for (int i = 0; i < len; i++) {
      if (num[i] - '0' >= n) {
        printf("Error");
        return 0;
      }
    }
    int result = 0;
    for (int i = 0; i < len; i++) {
      result += (num[i] - '0') * pow(n, i);
    }
    printf("%d", result);
  } else {
    for (int i = 0; i < len; i++) {
      if (num[i] - 'A' > n - 11) {
        printf("Error");
        return 0;
      }
    }
    int result = 0;
    for (int i = 0; i < len; i++) {
      if (num[i] - '0' < 10) {
        result += (num[i] - '0') * pow(n, i);
      } else {
        result += (num[i] - 'A' + 10) * pow(n, i);
      }
    }
    printf("%d", result);
  }
}
