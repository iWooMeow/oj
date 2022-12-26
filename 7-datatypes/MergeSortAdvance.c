#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10005
#define SWAP(a, b)                                                             \
  do {                                                                         \
    int t = a;                                                                 \
    a = b;                                                                     \
    b = t;                                                                     \
  } while (0);

void Merge(int *array, int l, int m, int r);
void MergeSortRecur(int *array, int l, int r);
void MergeSortIter(int *array, int length);
void QuickSortHoare(int *array, int left, int right);
void QuickSortPit(int *array, int left, int right);

int main() {
  int num = 0;
  scanf("%d", &num);
  int *array = (int *)malloc(sizeof(int) * num);
  for (int i = 0; i < num; i++) {
    scanf("%d", &array[i]);
  }
  // MergeSortIter(array, num);
  QuickSortPit(array, 0, num - 1);
  for (int i = 0; i < num; i++) {
    printf("%d ", array[i]);
  }
  return 0;
}
void MergeSortIter(int *array, int length) {
  int gap = 1;
  while (gap < length) {
    for (int i = 0; i < length; i += gap * 2) {
      int begin1 = i;
      int end1 = i + gap - 1;
      int begin2 = i + gap;
      int end2 = i + 2 * gap - 1;
      if (end1 >= length) {
        break;
      }
      if (begin2 >= length) {
        break;
      }
      if (end2 >= length) {
        end2 = length - 1;
      }
      Merge(array, begin1, end1, end2);
    }
    gap *= 2;
  }
}
void QuickSortHoare(int *array, int left, int right) {
  if (left >= right) {
    return;
  } else {
    int pivot = array[left];
    int leftCnt = left;
    int rightCnt = right;

    while (leftCnt < rightCnt) {
      while (array[rightCnt] >= pivot && leftCnt < rightCnt) {
        rightCnt--;
      }
      while (array[leftCnt] <= pivot && leftCnt < rightCnt) {
        leftCnt++;
      }
      SWAP(array[leftCnt], array[rightCnt]);
    }
    SWAP(array[left], array[leftCnt]);

    QuickSortHoare(array, left, leftCnt - 1);
    QuickSortHoare(array, leftCnt + 1, right);
  }
}
void QuickSortPit(int *array, int left, int right) {
  if (left >= right) {
    return;
  } else {
    int pivot = array[left];
    int leftCnt = left;
    int rightCnt = right;

    while (leftCnt < rightCnt) {
      while (array[rightCnt] >= pivot && leftCnt < rightCnt) {
        rightCnt--;
      }
      array[leftCnt] = array[rightCnt];
      while (array[leftCnt] <= pivot && leftCnt < rightCnt) {
        leftCnt++;
      }
      array[rightCnt] = array[leftCnt];
      // SWAP(array[leftCnt], array[rightCnt]);
    }
    // SWAP(array[left], array[leftCnt]);
    array[leftCnt] = pivot;

    QuickSortPit(array, left, leftCnt - 1);
    QuickSortPit(array, leftCnt + 1, right);
  }
}

void MergeSortRecur(int *array, int left, int right) {
  if (left == right) {
    return;
  } else {
    int middle = (left + right) / 2;
    MergeSortRecur(array, left, middle);
    MergeSortRecur(array, middle + 1, right);
    Merge(array, left, middle, right);
  }
}

void Merge(int *array, int left, int middle, int right) {
  // array[l] ~ array[m] array[m + 1] ~ array[r]
  int leftCnt = 0;
  int rightCnt = 0;
  int *tmpArray = (int *)malloc(sizeof(int) * (right - left + 1));
  memset(tmpArray, 0, sizeof(int) * (right - left + 1));
  while (leftCnt <= middle - left && rightCnt <= right - middle - 1) {
    if (array[left + leftCnt] <= array[middle + 1 + rightCnt]) {
      tmpArray[leftCnt + rightCnt] = array[left + leftCnt];
      leftCnt++;
    } else {
      tmpArray[leftCnt + rightCnt] = array[middle + 1 + rightCnt];
      rightCnt++;
    }
  }
  if (leftCnt > middle - left) {
    memcpy(tmpArray + leftCnt + rightCnt, array + middle + 1 + rightCnt,
           sizeof(int) * (right - middle - rightCnt));
  }
  if (rightCnt > right - middle - 1) {
    memcpy(tmpArray + leftCnt + rightCnt, array + left + leftCnt,
           (middle - left - leftCnt + 1) * sizeof(int));
  }
  memcpy(array + left, tmpArray, (right - left + 1) * sizeof(int));
}
