#include <stdbool.h>
#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

bool valid(int k, int va, int vb, int vc, int a, int b, int c, int a0, int b0,
           int c0);
int operate(int va, int a, int b); // pour b into a return a

int main() {
  int k, va, vb, vc, a, b, c, a0, b0, c0;
  scanf("%d%d%d%d%d%d%d%d%d%d", &k, &va, &vb, &vc, &a, &b, &c, &a0, &b0, &c0);
  if (valid(k, va, vb, vc, a, b, c, a0, b0, c0)) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}

bool valid(int k, int va, int vb, int vc, int a, int b, int c, int a0, int b0,
           int c0) {
  if (a == a0 && b == b0 && c == c0) {
    return true;
  } else if (a + b + c < a0 + b0 + c0 || k <= 0) {
    return false;
  } else {
    return (valid(k - 1, va, vb, vc, operate(va, a, b), 0, c, a0, b0, c0) ||
            valid(k - 1, va, vb, vc, operate(va, a, c), b, 0, a0, b0, c0) ||
            valid(k - 1, va, vb, vc, a, operate(vb, b, c), 0, a0, b0, c0) ||
            valid(k - 1, va, vb, vc, 0, operate(vb, b, a), c, a0, b0, c0) ||
            valid(k - 1, va, vb, vc, 0, b, operate(vc, c, a), a0, b0, c0) ||
            valid(k - 1, va, vb, vc, a, 0, operate(vc, c, b), a0, b0, c0));
  }
}

int operate(int va, int a, int b) {
  if (a + b >= va) {
    return va;
  } else {
    return a + b;
  }
}
