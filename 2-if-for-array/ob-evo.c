#include <stdio.h>
#include <stdlib.h>

void print(int i, char a);
void printS(int i, char a);
int cal(int x, int y);

int cal(int x, int y) { return (abs(x - y) - 1) * ((x - y) / abs(x - y)); }

void print(int i, char a) {
  for (int n = 1; n <= i; n++) {
    printf("%c", a);
  }
}

void printS(int i, char a) {
  int times = abs(i);
  switch (a) {
  case 'h':
    if (i >= 0) {
      print(times, 'R');
    } else {
      print(times, 'L');
    }
    break;
  case 'v':
    if (i >= 0) {
      print(times, 'U');
    } else {
      print(times, 'D');
    }
    break;
  }
}

int main() {
  int xa = 0, ya = 0, xb = 0, yb = 0, xc = 0, yc = 0;
  scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
  if ((xa == xb && xa == xc) &&
      ((yc > yb && yc < ya) || (yc < yb && yc > ya))) {
    printf("%d\n", abs(ya - yb) + 2);
    printS(cal(yc, ya), 'v');
    print(1, 'R');
    printS(abs(yc - ya) / (yc - ya) * 2, 'v');
    print(1, 'L');
    printS(cal(yb, yc), 'v');
  } else if ((ya == yb && yb == yc) &&
             ((xa < xc && xc < xb) || (xa > xc && xc > xb))) {
    printf("%d\n", abs(xa - xb) + 2);
    printS(cal(xc, xa), 'h');
    print(1, 'U');
    printS(abs(xb - xa) / (xb - xa) * 2, 'h');
    print(1, 'D');
    printS(cal(xb, xc), 'h');
  } else if (xa == xb) {
    printf("%d\n", abs(xa - xb) + abs(ya - yb));
    printS(yb - ya, 'v');
  } else if (ya == yb) {
    printf("%d\n", abs(xa - xb) + abs(ya - yb));
    printS(xb - xa, 'h');
  } else if ((yc == ya && xa >= xc && xc >= xb) ||
             (ya == yc && xa <= xc && xc <= xb) ||
             (xc == xb && yc >= yb && yc <= ya) ||
             (xc == xb && yc <= yb && yc >= ya)) {
    printf("%d\n", abs(xa - xb) + abs(ya - yb));
    printS(yb - ya, 'v');
    printS(xb - xa, 'h');
  } else if ((yc == yb && xa >= xc && xc >= xb) ||
             (yc == yb && xa <= xc && xc <= xb) ||
             (xa == xc && yc >= yb && yc <= ya) ||
             (xa == xc && yc <= yb && yc >= ya)) {
    printf("%d\n", abs(xa - xb) + abs(ya - yb));
    printS(xb - xa, 'h');
    printS(yb - ya, 'v');
  } else {
    printf("%d\n", abs(xa - xb) + abs(ya - yb));
    printS(xb - xa, 'h');
    printS(yb - ya, 'v');
  }
  return 0;
}
