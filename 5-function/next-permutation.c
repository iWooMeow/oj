#include <stdio.h>

#define SWAP(x, y)                                                             \
  do {                                                                         \
    int tmp = x;                                                               \
    x = y;                                                                     \
    y = tmp;                                                                   \
  } while (0)

int seq[2005];
int MaxSuffixIndex(const int seq[], int len);
int Search(const int seq[], int key, int len);

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &seq[i]);
  }
  int sufficIndex = MaxSuffixIndex(seq, n);
  // printf("%d",sufficIndex);
  int toBeExchangedIndex = Search(seq, seq[sufficIndex - 1], n);
  // printf("%d ",toBeExchangedIndex);
  SWAP(seq[toBeExchangedIndex], seq[sufficIndex - 1]);
  for (int i = sufficIndex; i <= (sufficIndex + n - 1) / 2; i++) {
    SWAP(seq[i], seq[sufficIndex + n - 1 - i]);
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", seq[i]);
  }
  return 0;
}

int Search(const int seq[], int key, int len) {
  int index = 0;
  for (int i = len - 1; i >= 0; i--) {
    if (seq[i] > key) {
      index = i;
      break;
    }
  }
  return index;
}

int MaxSuffixIndex(const int seq[], int len) {
  int tmp = seq[len - 1];
  int index = len - 1;
  for (int i = len - 2; i >= 0; i--) {
    if (seq[i] > tmp) {
      tmp = seq[i];
      index = i;
    } else {
      break;
    }
  }
  return index;
}
