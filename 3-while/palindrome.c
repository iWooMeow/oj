#include <stdio.h>

void gen1(char a, char b);
void gen2(char a, char b);

int count = 0;
int main() {
  int n = 0;
  scanf("%d", &n);
  char string[n];
  getchar();
  for (int i = 0; i < n; i++) {
    scanf("%c", &string[i]);
  }
  if (n % 2 == 0) {
    for (int i = 0; i <= n / 2 - 1; i++) {
      gen1(string[i], string[n - i - 1]);
    }
    for (int i = n / 2; i <= n - 1; i++) {
      gen2(string[i], string[n - i - 1]);
    }
  } else {
    for (int i = 0; i <= (n - 1) / 2 - 1; i++) {
      gen1(string[i], string[n - i - 1]);
    }
    for (int i = (n - 1) / 2; i <= n - 1; i++) {
      gen2(string[i], string[n - i - 1]);
    }
  }
  return 0;
}
void gen1(char a, char b) {
  if (a == '?' && b == '?') {
    printf("%.2d", count);
    count++;
  } else if (a == '?' && b != '?') {
    printf("%c", b);
  } else if (a != '?' && b == '?') {
    printf("%c", a);
  } else {
    printf("%c", a);
  }
}
void gen2(char a, char b) {
  if (a == '?' && b == '?') {
    count--;
    printf("%d%d", count % 10, count / 10);
  } else if (a == '?' && b != '?') {
    printf("%c", b);
  } else if (a != '?' && b == '?') {
    printf("%c", a);
  } else {
    printf("%c", a);
  }
}
