#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

void Print(const int *mul, int len);

char name[15];
int main() {
  int p1 = 0;
  int p2 = 0;
  scanf("%d%d", &p1, &p2);
  scanf("%s", name);
  int *poly1 = (int *)malloc(sizeof(int) * (p1 + 1));
  int *poly2 = (int *)malloc(sizeof(int) * (p2 + 1));
  int len = MAX(p1, p2) + 1;
  int *mul = (int *)malloc(sizeof(int) * (p1 + p2 + 1));
  int *add = (int *)malloc(sizeof(int) * len);
  int *sub = (int *)malloc(sizeof(int) * len);
  memset(mul, 0, sizeof(int) * (p1 + p2 + 1));
  for (int i = p1; i >= 0; i--) {
    scanf("%d", poly1 + i);
  }
  for (int i = p2; i >= 0; i--) {
    scanf("%d", &poly2[i]);
  }
  for (int i = 0; i <= p1; i++) {
    for (int j = 0; j <= p2; j++) {
      mul[i + j] += poly1[i] * poly2[j];
    }
  }
  for (int i = 0; i <= p1; i++) {
    add[i] = poly1[i];
  }
  for (int i = 0; i <= p2; i++) {
    add[i] += poly2[i];
  }
  for (int i = 0; i <= p1; i++) {
    sub[i] = poly1[i];
  }
  for (int i = 0; i <= p2; i++) {
    sub[i] -= poly2[i];
  }
  Print(add, len);
  putchar('\n');
  Print(sub, len);
  putchar('\n');
  Print(mul, p1 + p2 + 1);
  putchar('\n');
  return 0;
}

void Print(const int *coeffi, int len) {
  int i = len - 1;
  if (coeffi[i] == 1) {
    if (i == 1) {
      printf("%s", name);
    } else if (i > 1) {
      printf("%s^%d", name, i);

    } else {
      printf("%d", 1);
    }
  } else if (coeffi[i] == -1) {
    if (i == 1) {
      printf("-%s", name);
    } else if (i > 1) {
      printf("-%s^%d", name, i);

    } else {
      printf("%d", -1);
    }

  } else if (coeffi[i] != 0) {
    if (i == 1) {
      printf("%d%s", coeffi[i], name);
    } else if (i > 1) {
      printf("%d%s^%d", coeffi[i], name, i);

    } else {
      printf("%d", coeffi[i]);
    }
  }
  for (int i = len - 2; i >= 0; i--) {
    if (coeffi[i] == 1) {
      if (i == 1) {
        printf("+%s", name);
      } else if (i > 1) {
        printf("+%s^%d", name, i);

      } else {
        printf("%+d", 1);
      }
    } else if (coeffi[i] == -1) {
      if (i == 1) {
        printf("-%s", name);
      } else if (i > 1) {
        printf("-%s^%d", name, i);

      } else {
        printf("%d", -1);
      }
    } else if (coeffi[i] != 0) {
      if (i == 1) {
        printf("%+d%s", coeffi[i], name);
      } else if (i > 1) {
        printf("%+d%s^%d", coeffi[i], name, i);

      } else {
        printf("%+d", coeffi[i]);
      }
    }
  }
}
