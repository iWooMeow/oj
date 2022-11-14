#include <stdio.h>

#define SWAP(a, b)                                                             \
  do {                                                                         \
    int t = a;                                                                 \
    a = b;                                                                     \
    b = t;                                                                     \
  } while (0)

int x1, x2, y1, y2;
int a, b, c;

void rotateW();
void rotateA();
void rotateS();
void rotateD();

int main() {
  scanf("%d%d%d", &a, &b, &c);
  getchar();
  x1 = 0;
  y1 = 0;
  x2 = a;
  y2 = b;
  char tmp = 0;
  while ((tmp = getchar()) > 31) {
    switch (tmp) {
    case 'W':
      rotateW();
      break;
    case 'A':
      rotateA();
      break;
    case 'S':
      rotateS();
      break;
    case 'D':
      rotateD();
      break;
    }
  }
  printf("%d %d %d %d", x1, x2, y1, y2);
  return 0;
}

void rotateW() {
  int tmp = x1;
  x2 = x1;
  x1 = tmp - c;
  SWAP(a, c);
}
void rotateA() {
  int tmp = y1;
  y2 = y1;
  y1 = tmp - c;
  SWAP(b, c);
}
void rotateS() {
  int tmp = x2;
  x1 = x2;
  x2 = tmp + c;
  SWAP(a, c);
}
void rotateD() {
  int tmp = y2;
  y1 = y2;
  y2 = tmp + c;
  SWAP(b, c);
}
