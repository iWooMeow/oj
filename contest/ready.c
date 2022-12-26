#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Attributes[100][10];

int Judge(int a, int b, int c);
int IndexGen(int persons, int attrs);
int JudgeAttr(int IndexA, int IndexB, int IndexC);
void enumArg(int cnt, int start);
int n = 0;
int k = 0;
char tmp[5];
int ans = 0;

int main() {
  scanf("%d%d", &n, &k);
  for (int person = 0; person < n; ++person) {
    for (int attr = 0; attr < k; attr++) {
      scanf("%d", &Attributes[person][attr]);
    }
  }
  // ans = IndexGen(n, k);
  enumArg(4, 0);
  printf("%d", ans);
  return 0;
}

void enumArg(int cnt, int start) {
  if (cnt == -1) {
    int Cnt = 0;
    int i = tmp[0], j = tmp[1], k = tmp[2], n = tmp[3], m = tmp[4];
    Cnt += JudgeAttr(i, j, k);
    Cnt += JudgeAttr(i, j, m);
    Cnt += JudgeAttr(i, j, n);
    Cnt += JudgeAttr(i, k, m);
    Cnt += JudgeAttr(i, k, n);
    Cnt += JudgeAttr(i, m, n);
    Cnt += JudgeAttr(j, k, m);
    Cnt += JudgeAttr(j, k, n);
    Cnt += JudgeAttr(j, m, n);
    Cnt += JudgeAttr(k, m, n);
    if (Cnt >= 2) {
      ans += 1;
    }
  } else {
    for (int i = start; i < n; i++) {
      tmp[cnt] = i;
      enumArg(cnt - 1, i + 1);
    }
  }
}

// int IndexGen(int persons, int attrs) {
//   int Cnt = 0;
//   int ans = 0;
//   for (int i = 0; i < persons; i++) {
//     for (int j = 0; j < i; j++) {
//       for (int k = 0; k < j; k++) {
//         for (int m = 0; m < k; m++) {
//           for (int n = 0; n < m; n++) {
//             // if (i > j && j > k && k > m && m > n) {
//             Cnt += JudgeAttr(i, j, k);
//             Cnt += JudgeAttr(i, j, m);
//             Cnt += JudgeAttr(i, j, n);
//             Cnt += JudgeAttr(i, k, m);
//             Cnt += JudgeAttr(i, k, n);
//             Cnt += JudgeAttr(i, m, n);
//             Cnt += JudgeAttr(j, k, m);
//             Cnt += JudgeAttr(j, k, n);
//             Cnt += JudgeAttr(j, m, n);
//             Cnt += JudgeAttr(k, m, n);
//             if (Cnt >= 2) {
//               ans += 1;
//             }
//             Cnt = 0;
//             // }
//           }
//         }
//       }
//     }
//   }
//   return ans;
// }

int Judge(int a, int b, int c) {
  if (a == b && b == c) {
    return 1;
  } else if (a != b && a != c && b != c) {
    return 1;
  }
  return 0;
}

int JudgeAttr(int IndexA, int IndexB, int IndexC) {
  int stat = 1;
  for (int i = 0; i < k; i++) {
    if (Judge(Attributes[IndexA][i], Attributes[IndexB][i],
              Attributes[IndexC][i]) == 0) {
      stat = 0;
      break;
    }
  }
  return stat;
}
