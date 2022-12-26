#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100005

int parent[N];
int vis[N];
int ans[N];
int cnt;

int SearchMinNontracked(int length);
void QuickSortPit(int *array, int left, int right);
int find(int i);

int main() {
  int n = 0;
  scanf("%d", &n);
  char buf[10] = {0};
  scanf("%s", buf);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &parent[i]);
  }
  for (int i = 1; i <= n; i++) {
    find(i);
  }

  // while (SearchMinNontracked(n) >= 0) {
  //   int init = SearchMinNontracked(n);
  //   hasTracked[init] = 1;
  //   int target = parent[init];
  //   if (target == init) {
  //     ans[groupCnt] += 1;
  //     groupCnt++;
  //   } else {
  //     ans[groupCnt] += 1;
  //     while (target != init) {
  //       hasTracked[target] = 1;
  //       ans[groupCnt] += 1;
  //       target = parent[target];
  //     }
  //     groupCnt++;
  //   }
  // }
  for (int i = 1; i <= n; i++) {
    printf("%d ", parent[i]);
  }
  QuickSortPit(ans, 0, cnt - 1);
  if (strcmp(buf, "number") == 0) {
    printf("%d", cnt);
  } else if (strcmp(buf, "order") == 0) {
    for (int i = cnt - 1; i >= 0; i--) {
      printf("%d ", ans[i]);
    }
  }
  return 0;
}
int find(int i) {
  if (parent[i] != i && vis[i] == 0) {
    vis[i] = 1;
    parent[i] = find(parent[i]);
    ans[cnt]++;
  }
  // while (parent[i] != i && vis[i] == 0) {
  //   vis[i] = 1;
  //   i = parent[i];
  //   ans[cnt]++;
  // }
  // cnt++;
  return parent[i];
}

// int SearchMinNontracked(int length) {
//   for (int i = 1; i <= length; i++) {
//     if (hasTracked[i] == 0) {
//       return i;
//     }
//   }
//   return -1;
// }

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
    }
    array[leftCnt] = pivot;
    QuickSortPit(array, left, leftCnt - 1);
    QuickSortPit(array, leftCnt + 1, right);
  }
}
