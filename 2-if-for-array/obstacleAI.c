#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int direction(int a) {
  if (a != 0) {
    return (abs(a) / a);
  } else {
    return 0;
  }
}

void printS(int a) {
  switch (a) {
  case 1:
    printf("%c", 'R');
    break;
  case -1:
    printf("%c", 'L');
    break;
  case 2:
    printf("%c", 'U');
    break;
  case -2:
    printf("%c", 'D');
    break;
  }
}

int solution[10000] = {0};
int test(int xa, int xb, int xc, int ya, int yb, int yc) {
  // int xa = 0, ya = 0, xb = 0, yb = 0, xc = 0, yc = 0;
  // scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
  for (int i = 0; xb != xa || yb != ya;) {
    if (abs(xa - xb) > 0) {
      int tempx = direction(xb - xa);
      xa += tempx;
      if (xa == xc && ya == yc) {
        int temp0 = direction(yb - ya) == 0 ? 1 : direction(yb - ya);
        ya += temp0;
        solution[i]uu qqulu = temp0 * 2;
        solution[i + 1] = tempx;
        i += 2;
      } else {
        solution[i] = tempx;
        i++;
      }
    }
    if (abs(ya - yb) > 0) {
      int tempy = direction(yb - ya);
      ya += tempy;
      if (xa == xc && ya == yc) {
        int temp1 = direction(xb - xa) == 0 ? 1 : direction(xb - xa);
        xa += temp1;
        solution[i] = temp1;
        solution[i + 1] = tempy * 2;
        i += 2;
      } else {
        solution[i] = tempy * 2;
        i++;
      }
    }
  }
  int i = 0;
  for (; solution[i] != 0 || i < 999; i++) {
  }
  printf("%d\n", i);
  // for (i = 0; solution[i] != 0 || i < 1000; i++) {
  //   printS(solution[i]);
  // }
  return 0;
}
int check(int a, int b, int c, int d, int e, int f, char *p) {
  int x = a, y = b;
  int len = strlen(p);
  for (int i = 0; i < len; i++) {
    switch (p[i]) { // 目前可能没学到，这个 switch case 也可以用 4 个 if 来替代
    case 'U':
      y++;
      break; // 按照你自己打出来的路径走一遍
    case 'D':
      y--;
      break;
    case 'L':
      x--;
      break;
    case 'R':
      x++;
      break;
    }
    if (x == e && y == f) { // 中途碰到障碍了，退出。。
      printf("fail on %d, %d, %d, %d, %d, %d, %s", a, b, c, d, e, f, p);
      exit(1);
    }
  }
  if (x != c || y != d) { // 没到终点
    printf("fail on %d, %d, %d, %d, %d, %d, %s", a, b, c, d, e, f, p);
    exit(1);
  }
  return 0;
}
int main() {
  for (int a = 0; a < 2; a++)
    for (int b = 0; b < 2; b++)
      for (int c = 0; c < 2; c++)
        for (int d = 0; d < 2; d++)
          for (int e = 0; e < 2; e++)
            for (int f = 0; f < 2; f++) {
              if (a == c && b == d)
                continue; // 跳过点重合的情况
              if ((a == e && b == f) || (c == e && d == f))
                continue;
              printf("%d %d %d %d %d %d ", a, b, c, d, e, f);
              memset(solution, 0, 10000 * sizeof(int));
              test(a, b, c, d, e, f);
              // fscanf(stdout, "%s", path);
              // check(a, b, c, d, e, f,
              // path); // check if a, b can walk to c, d via path
              // fclose(stdout);
            }
}
