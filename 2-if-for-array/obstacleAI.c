#include <stdio.h>
#include <stdlib.h>

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

int main() {
  int xa = 0, ya = 0, xb = 0, yb = 0, xc = 0, yc = 0;
  int solution[10000] = {0};
  scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
  for (int i = 0; xb != xa || yb != ya;) {
    if (abs(xa - xb) > 0) {
      int tempx = direction(xb - xa);
      xa += tempx;
      if (xa == xc && ya == yc) {
        int temp0 = direction(yb - ya) == 0 ? 1 : direction(yb - ya);
        ya += temp0;
        solution[i] = temp0 * 2;
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
  for (; solution[i] != 0; i++) {
  }
  printf("%d\n", i);
  for (i = 0; solution[i] != 0; i++) {
    printS(solution[i]);
  }
  return 0;
}
