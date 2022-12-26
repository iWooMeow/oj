//
// Created by Ryan Dylan on 12/23/22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    freopen("ans.out", "w+", stdout);
    freopen("test.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    int **board = malloc(n * sizeof *board);
    for (register int i = 0; i < n; i++) {
        board[i] = malloc(m * sizeof **board);
    }
    for (register int row = 0; row < n; row++) {
        for (register int col = 0; col < m; col++) {
            board[row][col] = (row + 1) * m + col + 1;
        }
    }
    int x1, y1, x2, y2, x3, y3, x4, y4, a;
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &a);
        x1--;
        y1--;
        x2--;
        y2--;
        x3--;
        y3--;
        x4--;
        y4--;
        int leny = y2 - y1;
        int lenx = x2 - x1;
        int *tmp = malloc((leny + 1) * sizeof(int));
        for (register int i = 0; i <= lenx; i++) {
            memcpy(tmp, &board[x1 + i][y1], sizeof(int) * (leny + 1));
            memcpy(&board[x1 + i][y1], &board[x3 + i][y3], sizeof(int) * (leny + 1));
            memcpy(&board[x3 + i][y3], tmp, sizeof(int) * (leny + 1));
        }
        long long ans = 0;
        a--;
        for (register int i = 0; i < m; i++) {
            ans += board[a][i];
        }
        printf("%lld\n", ans);
    }

    return 0;
}