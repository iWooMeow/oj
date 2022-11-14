#include <stdio.h>

char stack[15];
int output[30];

int main() {
  int T;
  int status = 1;
  int index = 0;
  char tmp = 0;
  scanf("%d", &T);
  getchar();
  for (int i = 0; i < T; i++) {
    while (1) {
      tmp = getchar();
      if (tmp <= 31) {
        break;
      }
      if (tmp == '(' || tmp == '[' || tmp == '{') {
        stack[index++] = tmp;
      } else {
        if (tmp == ')' && stack[index - 1] == '(') {
          stack[index - 1] = 0;
          index--;
        } else if (tmp == ']' && stack[index - 1] == '[') {
          stack[index - 1] = 0;
          index--;
        } else if (tmp == '}' && stack[index - 1] == '{') {
          stack[index - 1] = 0;
          index--;
        } else {
          status = 0;
        }
      }
    }
    if (status == 1 && index == 0) {
      output[i] = 1;
    }
    status = 1;
    index = 0;
  }
  for (int i = 0; i < T; i++) {
    if (output[i] == 1) {
      printf("True\n");
    } else {
      printf("False\n");
    }
  }
  return 0;
}
