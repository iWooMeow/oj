#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool validate(int x, int y);
bool proceedx();
bool proceedy();
bool proceedDirectx();
bool proceedDirecty();
void print(int i, char a);
int test(int x0, int y0, int x1, int y1, int xc, int yc);

int x0 = 0, y0 = 0, x1 = 0, y1 = 0, xc = 0, yc = 0;
int x = 0, y = 0;
int ix = 0, iy = 0;
int main() {
  for (; x0 < 6; x0++) {
    for (; y0 < 6; y0++) {
      for (; x1 < 6; x1++) {
        for (; y1 < 6; y1++) {
          for (; xc < 6; xc++) {
            for (; yc < 6; yc++) {
              test(x0, y0, x1, y1, xc, yc);
            }
          }
        }
      }
    }
  }
}
int test(int x0, int y0, int x1, int y1, int xc, int yc) {
  // scanf("%d%d%d%d%d%d", &x0, &y0, &x1, &y1, &xc, &yc);
  x = x0;
  y = y0;
  if (((y0 == y1) && (x0 < xc) && (xc < x1)) ||
      ((y0 == y1) && (x0 > xc) && (xc > x1))) {

    printf("%d\n", abs(x0 - x1) + 2);

  } else if (((x0 == x1) && (y0 < yc) && (yc < y1)) ||
             ((x0 == x1) && (y0 > yc) && (yc > y1))) {
    printf("%d\n", abs(y0 - y1) + 2);
  } else {
    printf("%d\n", abs(x0 - x1) + abs(y0 - y1));
  }
  if (proceedx() && proceedy()) {
    // printf("%d\n", abs(y0-y1) + abs(x0-x1));
    if (ix <= 0) {
      print(-1 * ix, 'L');
    } else if (ix >= 0) {
      print(ix, 'R');
    }

    if (iy <= 0) {
      print(-1 * iy, 'D');
    } else if (iy >= 0) {
      print(iy, 'U');
    }
  } else if (proceedy() && proceedx()) {
    // printf("%d\n", abs(y0-y1) + abs(x0-x1));
    if (iy <= 0) {
      print(-1 * iy, 'D');
    } else if (iy >= 0) {
      print(iy, 'U');
    }
    if (ix <= 0) {
      print(-1 * ix, 'L');
    } else if (ix >= 0) {
      print(ix, 'R');
    }
  } else if (proceedDirectx()) {
  } else if (proceedDirecty()) {
  }
  return 0;
}

bool proceedDirecty() {
  if (x == x1) {
    // printf("%d\n", abs(y1 - y0) + 2);
    if (y0 < y1) {
      print(yc - y0 - 1, 'U');
      print(1, 'R');
      print(2, 'U');
      print(1, 'L');
      print(y1 - yc - 1, 'U');

    } else {
      print(y0 - yc - 1, 'D');
      print(1, 'R');
      print(2, 'D');
      print(1, 'L');
      print(yc - y1 - 1, 'D');
    }
    return true;
  }

  else {

    return false;
  }
}
bool proceedDirectx() {
  if (y == y1) {
    // printf("%d\n", abs(x1 - x0) + 2);
    if (x0 < x1) {
      print(xc - x0 - 1, 'R');
      print(1, 'U');
      print(2, 'R');
      print(1, 'D');
      print(x1 - xc - 1, 'R');

    } else {
      print(x0 - xc - 1, 'L');
      print(1, 'U');
      print(2, 'L');
      print(1, 'D');
      print(xc - x1 - 1, 'L');
    }
    return true;
  }

  else {

    return false;
  }
}
void print(int i, char a) {
  for (int n = 1; n <= i; n++) {
    printf("%c", a);
  }
}
bool validate(int x, int y) {
  if (x == xc && y == yc) {
    return false;
  }
  return true;
}

bool proceedx() {
  for (; x != x1;) {
    if (x < x1) {
      x++;
      ix++;
      if (!validate(x, y)) {
        x = x0;
        ix = 0;
        return false;
      }
    } else if (x > x1) {
      x--;
      ix--;
      if (!validate(x, y)) {
        x = x0;
        ix = 0;
        return false;
      }
    }
  }
  return true;
}
bool proceedy() {
  for (; y != y1;) {
    if (y < y1) {
      y++;
      iy++;
      if (!validate(x, y)) {
        y = y0;
        iy = 0;
        return false;
      }
    } else if (y > y1) {
      y--;
      iy--;
      if (!validate(x, y)) {
        y = y0;
        iy = 0;
        return false;
      }
    }
  }
  return true;
}
