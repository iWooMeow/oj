#include <stdio.h>
int main() {
  float a = 0;
  char b[100] = "";
  // fgets(b, 50, stdin);
  scanf("%c", &b[1]);
  printf("%s", b);
  return 0;
}
