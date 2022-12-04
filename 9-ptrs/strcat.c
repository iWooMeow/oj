#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StrCat(char *s1, char *s2);

int main() {
  int T;
  char *s1 = malloc(sizeof(char) * 1000);
  char *s2 = malloc(sizeof(char) * 1000);
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    memset(s1, 0, sizeof(char) * 1000);
    memset(s2, 0, sizeof(char) * 1000);
    scanf("%s", s1);
    scanf("%s", s2);
    StrCat(s1, s2);
    printf("%s\n", s1);
  }

  return 0;
}

void StrCat(char *s1, char *s2) {
  int l1 = strlen(s1);
  int l2 = strlen(s2);
  int count = 0;
  for (int i = 0; i < l1; i++) {
    if (strncmp(s1 + i, s2, l1 - i) == 0) {
      count = l1 - i;
      break;
    }
  }

  strcat(s1, s2 + count);
}
