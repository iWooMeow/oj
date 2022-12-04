#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Cap(char c);
char UnCap(char c);

int main() {
  char *input = (char *)malloc(5005 * sizeof(char));
  memset(input, 0, 5005 * sizeof(char));
  fgets(input, 5000 * sizeof(char), stdin);
  int len = strlen(input);
  *(input) = Cap(*(input));
  for (int i = 1; i < len; i++) {
    if (*(input + i) == ' ') {
      i++;
      *(input + i) = Cap(*(input + i));
    } else if (*(input + i) != ' ') {

      *(input + i) = UnCap(*(input + i));
    }
  }
  // printf("%s", input);
  for (int i = 0; i < len - 1; i++) {
    printf("%c", *(input + i));
  }

  return 0;
}

char UnCap(char c) {
  char ans = c;
  if (c >= 'A' && c <= 'Z') {
    ans += 32;
  }
  return ans;
}
char Cap(char c) {
  char ans = c;
  if (c >= 'a' && c <= 'z') {
    ans -= 32;
  }
  return ans;
}
