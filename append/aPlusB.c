#include <stdio.h>
#include <string.h>
#define DIGIT 10001

char buffera[DIGIT] = {0}, bufferb[DIGIT] = {0};

void charConvert(int len, char buffer[], int store[]);
void output(int result[]);
void resetBuffer(char buffer[]);
int *add(int a[], int b[], int result[]);

int main() {
  while (scanf("%s%s", buffera, bufferb) ==2) {
    int a[DIGIT] = {0}, b[DIGIT] = {0}, result[DIGIT] = {0};
    int alen = 0, blen = 0;
    alen = strlen(buffera);
    blen = strlen(bufferb);
    charConvert(alen, buffera, a);
    charConvert(blen, bufferb, b);
    output(add(a, b, result));
    resetBuffer(buffera);
    resetBuffer(bufferb);
  }
  return 0;
}

void charConvert(int len, char buffer[], int store[]) {
  for (int i = 0; i < len; i++) {
    store[i] = buffer[len - 1 - i] - '0';
  }
}

int *add(int a[], int b[], int result[]) {
  for (int i = 0; i < DIGIT - 1; i++) {
    if (a[i] + b[i] < 10) {
      result[i] += a[i] + b[i];
    } else {
      result[i] += a[i] + b[i] - 10;
      result[i + 1]++;
    }
  }
  return result;
}

void output(int result[]) {
  int i = 0;
  for (i = DIGIT - 1; result[i] == 0 && i != 0;) {
    i--;
  }
  for (; i >= 0; i--) {
    printf("%d", result[i]);
  }
  putchar('\n');
}

void resetBuffer(char buffer[]) {
  for (int i = 0; i < DIGIT; i++) {
    buffer[i] = '0';
  }
}
