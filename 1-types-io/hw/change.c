#include <stdio.h>

int main() {
  int input;
  int rmb50;
  int rmb20;
  int rmb10;
  int rmb5;
  int rmb1;
  scanf("%d", &input);
  rmb50 = input / 50;
  input = input - rmb50 * 50;
  rmb20 = input / 20;
  input = input - rmb20 * 20;
  rmb10 = input / 10;
  input = input - rmb10 * 10;
  rmb5 = input / 5;
  input = input - rmb5 * 5;
  rmb1 = input;
  printf("%d\n%d\n%d\n%d\n%d", rmb50, rmb20, rmb10, rmb5, rmb1);
  return 0;
}
