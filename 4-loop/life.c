#include <stdio.h>

#define SIZE 10000

char len1[SIZE];
char len2[SIZE];

int search(char array[], int position, char target);
int countArray(char array[]);
void copy(char len1[], char len2[]);
// the most hard part is how to address the array with 3 empty elements
int main() {
  int n = 0;
  scanf("%d", &n);
  scanf("%s", len2);
  for (int i = 3; i <= 5000; i++) {
    len1[i] = len2[i - 3];
  }
  copy(len2, len1);
  for (int i = 0; i < n; i++) {
    int length1 = countArray(len1);
    for (int i = 3; i <= length1 + 2; i++) {
      if (len1[i] == '.' && search(len1, i, 'A') <= 4 &&
          search(len1, i, 'A') >= 2 && search(len1, i, 'B') == 0) {
        len2[i] = 'A';
      } else if (len1[i] == '.' && search(len1, i, 'B') <= 4 &&
                 search(len1, i, 'B') >= 2 && search(len1, i, 'A') == 0) {
        len2[i] = 'B';
      } else if (len1[i] == 'A' && search(len1, i, 'B') != 0) {
        len2[i] = '.';
      } else if (len1[i] == 'B' && search(len1, i, 'A') != 0) {
        len2[i] = '.';
      } else if (len1[i] == 'A' && search(len1, i, 'A') >= 5) {
        len2[i] = '.';
      } else if (len1[i] == 'B' && search(len1, i, 'B') >= 5) {
        len2[i] = '.';
      } else if (len1[i] == 'A' && search(len1, i, 'A') <= 1) {
        len2[i] = '.';
      } else if (len1[i] == 'B' && search(len1, i, 'B') <= 1) {
        len2[i] = '.';
      }
    }
    copy(len1, len2);
  }
  for (int i = 3;; i++) {
    if (len1[i] <= 32) {
      break;
    }
    printf("%c", len1[i]);
  }
  return 0;
}

int search(char array[], int position, char target) {
  int result = 0;
  for (int i = 0; i < 3; i++) {
    if (array[position - 3 + i] == target) {
      result++;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (array[position + 1 + i] == target) {
      result++;
    }
  }
  return result;
}
int countArray(char array[]) {
  int count = 0;
  for (int i = 3;; i++) {
    if (array[i] > 32) {
      count++;
    } else {
      break;
    }
  }
  return count;
}
void copy(char len1[], char len2[]) {
  for (int i = 3; i < SIZE; i++)
    len1[i] = len2[i];
}
