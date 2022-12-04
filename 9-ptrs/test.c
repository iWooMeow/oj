#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buf = malloc(sizeof(char) * 4096);
  memset(buf, 0, sizeof(char) * 4096);
  *buf = 'a';
  *(buf + 1) = 0;
  // *(buf + 1) = 'n';
  char t = '0';
  printf("%lu\n", strlen(buf));
  printf("%ld", strchr(buf, 'a') - buf);

  return 0;
}
