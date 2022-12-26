#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct team {
  char teamName[25];
  char memberName[11][25];
  int memberScore[11][3];
} Team;

int cmp0(const void *a, const void *b);
int cmp1(const void *a, const void *b);
int cmp2(const void *a, const void *b);

int main() {
  int n = 0;
  scanf("%d", &n);
  Team *teams = (Team *)malloc(n * sizeof(Team));
  for (int i = 0; i < n; i++) { // nth team
    scanf("%s", teams[i].teamName);
    for (int j = 0; j < 11; j++) { // jth member
      scanf("%s", teams[i].memberName[j]);
      scanf("%d%d%d", &teams[i].memberScore[j][0], &teams[i].memberScore[j][1],
            &teams[i].memberScore[j][2]);
    }
  }
  qsort(teams, n, sizeof(Team), cmp0);
  for (int i = 0; i < n; i++) {
    printf("%s ", teams[i].teamName);
  }
  putchar('\n');
  qsort(teams, n, sizeof(Team), cmp1);
  for (int i = 0; i < n; i++) {
    printf("%s ", teams[i].teamName);
  }
  putchar('\n');
  qsort(teams, n, sizeof(Team), cmp2);
  for (int i = 0; i < n; i++) {
    printf("%s ", teams[i].teamName);
  }

  return 0;
}

int cmp(const void *a, const void *b, int index) {
  int sumA = 0;
  int sumB = 0;
  for (int i = 0; i < 11; i++) {
    sumA += ((Team *)a)->memberScore[i][index];
  }
  for (int i = 0; i < 11; i++) {
    sumB += ((Team *)b)->memberScore[i][index];
  }
  if (sumA == sumB) {
    return 0;
  } else if (sumA < sumB) {
    return 1;
  } else {
    return -1;
  }
}
int cmp0(const void *a, const void *b) { return cmp(a, b, 0); }
int cmp1(const void *a, const void *b) { return cmp(a, b, 1); }
int cmp2(const void *a, const void *b) { return cmp(a, b, 2); }
