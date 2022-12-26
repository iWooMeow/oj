#include <stdio.h>

void enumArg(int cnt, int start);

char tmp[5];

int main() {
  enumArg(0, 0);
  return 0;
}

void enumArg(int cnt, int start) {
  if (cnt == 5) {
    for (int i = 0; i < 5; i++) {
      printf("%d ", tmp[i]);
    }
    putchar('\n');
  } else {
    for (int i = start; i < 7; i++) {
      tmp[cnt] = i;
      enumArg(cnt + 1, i + 1);
    }
  }
}
