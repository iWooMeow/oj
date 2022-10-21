#include <stdio.h>

// void loop(int i, int limit, int casualty[]);

int main() {
  int n = 0, k = 0, count = 0;
  scanf("%d%d", &n, &k);
  int casualty[n];
  if (n == 1) {
    printf("1");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    casualty[i] = 0;
  }
  int index = 0;
  //NEVER use casualty[k-1]=0
  for (index = 0; count < n - 1;) {
    index--;
    for (int j = 0; j < k; j++) {
      index++;
      while (index > n - 1 || casualty[index] == 1) {
        if (index > n - 1) {
          index = 0;
        } else if (casualty[index] == 1) {
          index++;
        }
      }
    }
    casualty[index]++;
    count++;
  }
  for (int i = 0; i < n; i++) {
    if (casualty[i] != 1) {
      printf("%d\n", i + 1);
    }
  }

  return 0;
}
// void loop(int i, int limit, int casualty[]) {
//   i++;
//   while (i > limit || casualty[i] == 1) {
//     if (i > limit) {
//       i = 0;
//     } else if (casualty[i] == 1) {
//       i++;
//     }
//   }
// }
