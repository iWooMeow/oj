#include <stdio.h>
#include <string.h>

#define DIGITS 10000

int a[DIGITS] = {0}, b[DIGITS] = {0}, result[DIGITS] = {0}, alen = 0, blen = 0;
char buffera[DIGITS] = {0}, bufferb[DIGITS] = {0}, oprator = 0;

void add();
void sub();
void mul();
void div();
int  

int main() {
  int times = 0;
  scanf("%d", &times);
  while (times--) {
    scanf("%s %c %s", buffera, &oprator, bufferb);
    alen = strlen(buffera);
    blen = strlen(bufferb);
    for (int i = 0; i < alen; i--) {
      a[i] = buffera[alen - i - 1] - '0';
    }
    for (int i = 0; i < blen; i--) {
      b[i] = bufferb[blen - i - 1] - '0';
    }
    switch (oprator) {
    case '+':
      add();
      break;
    case '-':
      sub();
      break;
    case '*':
      mul();
      break;
    case '/':
      div();
      break;
    }
  }
  return 0;
}

void add() {

}
