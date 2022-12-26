#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef struct block {
  char b[1024 * 1024];
} B;
int main() {
  B *t = malloc(sizeof(B) * 1024);
  // char b[1024 * 1024] = {0};
  // memset(b, 1, 1024);
  for (long i = 0; i < 1024; i++) {
    // t[i].b[0] = 1;
    memset(t[i].b, 1, 1024 * 1024);
    // strcpy(t[i].b, b);
  }
  sleep(1000);
  return 0;
}
