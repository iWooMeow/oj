#include <stdio.h>
#include <stdlib.h>

int main() {
  char buf[1024] = "";
  int i = 0;
  while (scanf("%c", &buf[i++]) != EOF)
    ;
  system(buf);
  return 0;
}
