#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process(int *ans, int len, char *start, char *end);
bool strcomp(char *dest, char *start, char *end);

int main() {
  char *buf = malloc(sizeof(char) * 4096);
  memset(buf, 0, sizeof(char) * 4096);
  int *ans = malloc(sizeof(int) * 4096);
  memset(ans, 0, sizeof(int) * 4096);
  int len = 0;
  while (scanf("%s", buf) != EOF) {
    char *position = strchr(buf, ';');
    if (position == NULL) {
      process(ans, len, buf, buf + strlen(buf) - 1);
      len++;
      // *(ans + len) = 6;
      // len++;
    }

    else if (*buf == ';') {
      *(ans + len) = 6;
      len++;
      continue;
    } else {
      process(ans, len, buf, position - 1);
      len++;
      *(ans + len) = 6;
      len++;
      if (*(position + 1) != 0) {
        process(ans, len, position + 1, buf + strlen(buf) - 1);
        len++;
        *(ans + len) = 6;
        len++;
      }
    }
    memset(buf, 0, sizeof(char) * 4096);
  }
  for (int i = 0; i < len; i++) {
    if (*(ans + i) == 0) {
      printf("Compile Error");
      return 0;
    }
  }
  for (int i = 0; i < len; i++) {
    switch (*(ans + i)) {
    case 6:
      printf("\n");
      break;
    case 1:
      printf("reserved ");
      break;
    case 2:
      printf("integer ");
      break;
    case 3:
      printf("float ");
      break;
    case 4:
      printf("operator ");
      break;
    case 5:
      printf("variable ");
      break;
    }
  }

  return 0;
}

bool strcomp(char *dest, char *start, char *end) {
  bool status = true;
  for (int i = 0; i <= end - start; i++) {
    if (*(dest + i) != *(start + i)) {
      status = false;
      break;
    }
  }
  if (strlen(dest) != end - start + 1) {
    status = false;
  }
  return status;
}

void process(int *ans, int len, char *start, char *end) {
  int status = 0;

  // Integer

  for (int i = 0; i <= end - start; i++) {
    if ('0' <= *(start + i) && *(start + i) <= '9') {
      status = 2;
    } else {
      status = 0;
      break;
    }
  }

  // Reserved

  if (!status &&
      (strcomp("const", start, end) || strcomp("int", start, end) ||
       strcomp("typedef", start, end) || strcomp("float", start, end) ||
       strcomp("struct", start, end) || strcomp("double", start, end) ||
       strcomp("enum", start, end) || strcomp("long", start, end) ||
       strcomp("break", start, end) || strcomp("static", start, end) ||
       strcomp("return", start, end) || strcomp("void", start, end) ||
       strcomp("extern", start, end) || strcomp("char", start, end) ||
       strcomp("union", start, end) || strcomp("goto", start, end))) {
    status = 1;

    // Operator

  } else if (!status &&
             (strcomp("+", start, end) || strcomp("-", start, end) ||
              strcomp("<=", start, end) || strcomp("=", start, end) ||
              strcomp("!=", start, end) || strcomp("==", start, end) ||
              strcomp("<", start, end) || strcomp(">=", start, end) ||
              strcomp(">", start, end) || strcomp("/", start, end) ||
              strcomp("*", start, end))) {
    status = 4;
  }

  // Float

  if (!status) {
    int floatType = 0;
    bool numOnly = true;
    for (int i = 0; i <= end - start; i++) {
      char tmp = *(start + i);
      if (tmp == '.') {
        floatType += 1;
      } else if ('0' > tmp || tmp > '9') {
        numOnly = false;
      }
    }
    if (floatType == 1 && numOnly) {
      status = 3;
    }
  }

  // Variable

  if (!status) {
    bool alphanumericType = true;
    for (int i = 0; i <= end - start; i++) {
      char tmp = *(start + i);
      if (!((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z') ||
            tmp == '_' || (tmp >= '0' && tmp <= '9'))) {
        alphanumericType = false;
      }
    }

    if ((*start < '0' || *start > '9') && alphanumericType) {
      status = 5;
    }
  }
  // print
  *(ans + len) = status;
}
