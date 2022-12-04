#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *regex = malloc(sizeof(char) * 200);
  memset(regex, 0, sizeof(char) * 200);
  char *cmd = malloc(sizeof(char) * 100);
  memset(cmd, 0, sizeof(char) * 100);
  char *options = malloc(sizeof(char) * 2000);
  memset(options, 0, sizeof(char) * 2000);
  bool *hasArgs = malloc(sizeof(bool) * 2000);
  memset(hasArgs, 0, sizeof(bool) * 2000);
  char **ans = malloc(sizeof(char *) * 1001);
  for (int i = 0; i < 1000; i++) {
    *(ans + i) = malloc(sizeof(char) * 10);
    memset(*(ans + i), 0, sizeof(char) * 10);
  }
  scanf("%s", regex);

  // Parse rule

  int len = strlen(regex);
  int cnt = 0;
  for (int i = 0; i < len; i++) {
    if (*(regex + i) == ':') {
      *(hasArgs + cnt - 1) = true;
    } else {
      *(options + cnt) = *(regex + i);
      cnt++;
    }
  }

  // Parse command

  int anscnt = 0;
  char *name = malloc(sizeof(char) * 1000);
  scanf("%s", name); // Pass exec
  while (scanf("%s", cmd) != EOF) {
    if (*cmd == '-') {
      char option = *(cmd + 1);
      char *ptr = strchr(options, option);
      if (ptr == NULL) {
        printf("%s: invalid option -- '%c'", name, option);
        return 0;
      } else if (!*(hasArgs + (ptr - options))) {
        **(ans + anscnt) = option;
        anscnt++;
      } else {
        if (scanf("%s", cmd) == EOF) {
          printf("%s: option requires an argument -- '%c'", name, option);
          return 0;
        } else {
          // printf("%c", **(ans + anscnt));
          **(ans + anscnt) = option;
          strcat(*(ans + anscnt), "=");
          strcat(*(ans + anscnt), cmd);
          anscnt++;
        }
      }
    }
  }

  printf("%s\n", name);
  for (int i = 0; i < anscnt; i++) {
    printf("%s\n", *(ans + i));
  }
  return 0;
}
