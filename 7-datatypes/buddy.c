#include <math.h>
#include <stdio.h>

int memory[1000005];
int Allocated[1000005];
int len = 0;

void Query();
void Allocate(int id, int m);
int Adequate(int m);
void move(int index);

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  memory[0] = n;
  len++;
  for (int i = 0; i < q;) {
    getchar();
    if (getchar() == 'Q') {
      Query();
      i++;
    } else {
      getchar();
      int id, m;
      scanf("%d%d", &id, &m);
      Allocate(id, m);
      i++;
    }
  }

  return 0;
}

void Allocate(int id, int m) {
  int size = Adequate(m);
  int tmp = 1;
  int memo = -1;

  while (tmp) {
    // search for proper memory location
    if (memo > 0) {
      Allocated[memo] = id;
      break;
    }
    for (int i = len - 1; i >= 0; i--) {
      if (size == memory[i] && Allocated[i] == 0) {
        Allocated[i] = id;
        tmp = 0;
        break;
      }
    }
    // split available memory
    for (int i = len - 1; tmp == 1 && i >= 0; i--) {
      if (size < memory[i] && Allocated[i] == 0) {
        memo = i;
        while (size < memory[memo]) {
          move(memo);
          memory[memo + 1] -= 1;
          memory[memo] = memory[memo + 1];
          memo += 1;
        }
        break;
      }
    }
  }
}

void Query() {
  printf("%d\n", len);
  for (int i = len - 1; i >= 0; i--) {
    printf("%d ", Allocated[i]);
  }
  putchar('\n');
}

int Adequate(int m) {
  int indice = (int)(log(m) / log(2));
  if (pow(2, indice) == m) {
    return indice;
  } else {
    return indice + 1;
  }
}

void move(int index) {
  for (int i = len - 1; i >= index; i--) {
    memory[i + 1] = memory[i];
  }
  for (int i = len - 1; i >= index; i--) {
    Allocated[i + 1] = Allocated[i];
  }
  len++;
}
