#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SubString(const char *str, const char *sub, int lenStr, int lenSubstr);

int main() {
  char *str = (char *)malloc(sizeof(char) * 100005);
  char *substr = (char *)malloc(sizeof(char) * 100005);
  memset(str, 0, sizeof(char) * 100005);
  memset(str, 0, sizeof(char) * 100005);
  scanf("%s", str);
  scanf("%s", substr);
  int lenStr = strlen(str);
  int lenSubstr = strlen(substr);
  SubString(str, substr, lenStr, lenSubstr);
  free(str);
  free(substr);
  return 0;
}

void SubString(const char *str, const char *sub, int lenStr, int lenSubstr) {
  bool status = true;
  for (int i = 0; i <= lenStr - lenSubstr; i++) {
    status = true;
    for (int j = 0; j < lenSubstr; j++) {
      if (*(str + j + i) != *(sub + j)) {
        status = false;
        break;
      }
    }
    if (status) {
      printf("%d ", i);
    }
  }
}
