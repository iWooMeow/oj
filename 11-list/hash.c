#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000000

typedef struct link {
  char *first;
  struct link *rest;
} Link;

Link *hashSet[N];

int hash(char *s);
// void Insert(Link *link, char *s);
int Search(Link *link, char *str);
// char buf[N][1000];

int main() {
  int m, q;
  scanf("%d%d", &m, &q);
  char buf[1000];
  for (int i = 0; i < m; i++) {
    scanf("%s", buf);
    int index = hash(buf);
    if (hashSet[index] == NULL) {
      hashSet[index] = malloc(sizeof(Link));
      hashSet[index]->first = malloc(sizeof(char) * (strlen(buf) + 1));
      strcpy(hashSet[index]->first, buf);
      hashSet[index]->rest = NULL;
    } else if (!Search(hashSet[index], buf)) {
      Link *new = malloc(sizeof(Link));
      new->first = malloc(sizeof(char) * (1 + strlen(buf)));
      strcpy(new->first, buf);
      new->rest = hashSet[index]->rest;
      hashSet[index]->rest = new;
    }
  }
  for (int i = 0; i < q; i++) {
    scanf("%s", buf);
    int index = hash(buf);
    if (hashSet[index] == NULL) {
      printf("No\n");
    } else if (Search(hashSet[index], buf)) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}
int Search(Link *link, char *str) {
  while (link != NULL) {
    if (strcmp(link->first, str) == 0) {
      return 1;
    }
    link = link->rest;
  }
  return 0;
}

int hash(char *str) {
  int hash = 0;
  while (*str) {
    hash = hash * 131 + *str++;
  }
  return (hash % N + N) % N;
}

// int hash(char *s) {
//   int len = strlen(s);
//   int ret = 0;
//   for (int i = 0; i < len; i++)
//     ret = (ret + s[i] * (i + 1)) % N;
//   return ret;
// }
