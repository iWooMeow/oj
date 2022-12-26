//
// Created by Ryan Dylan on 12/22/22.
//

#include <stdio.h>
#include <stdlib.h>

char board[20][21];

int HorizontalFive();

int VerticalFive();

int SlopeFive1();

int SlopeFive2();

int JudgeFive(char a, char b, char c, char d, char e);

int Chk();

int main() {
    int T;
    scanf("%d", &T);
    Loop:
    while (T--) {
        for (int row = 0; row < 20; row++) {
            scanf("%s", board[row]);
        }
        int black = 0;
        for (register int row = 0; row < 20; row++) {
            for (register int col = 0; col < 20; col++) {
                printf("%c", board[row][col]);
            }
            putchar('\n');
        }
        for (register int row = 0; row < 20; row++) {
            for (register int col = 0; col < 20; col++) {
                if (board[row][col] == '_') {
                    board[row][col] = '*';
                    if (Chk()) {
                        puts("Lose");
                        goto Loop;
                    }
                    board[row][col] = '#';
                    if (Chk()) {
                        black++;
                    }
                    board[row][col] = '_';
                }
            }
        }
        if (black >= 2) {
            puts("Win");
        } else {
            puts("Not Sure");
        }

    }
    return 0;
}

int Chk() {
    return HorizontalFive() || VerticalFive() || SlopeFive1() || SlopeFive2();
}

int JudgeFive(char a, char b, char c, char d, char e) {
    return (a == '*' && b == '*' && c == '*' && d == '*' && e == '*') ||
           (a == '#' && b == '#' && c == '#' && d == '#' && e == '#');
}

int HorizontalFive() {
    for (register int row = 0; row <= 19; row++) {
        for (register int col = 0; col <= 15; col++) {
            if (JudgeFive(board[row][col],
                          board[row][col + 1],
                          board[row][col + 2],
                          board[row][col + 3],
                          board[row][col + 4])
                    ) {
                return 1;
            }
        }
    }
    return 0;
}

int VerticalFive() {
    for (register int row = 0; row <= 15; row++) {
        for (register int col = 0; col <= 19; col++) {
            if (JudgeFive(board[row][col],
                          board[row + 1][col],
                          board[row + 2][col],
                          board[row + 3][col],
                          board[row + 4][col])
                    ) {
                return 1;
            }
        }
    }
    return 0;
}

int SlopeFive2() {
    for (register int row = 0; row <= 14; row++) {
        for (register int col = 0; col <= 14; col++) {
            if (JudgeFive(board[row][col],
                          board[row + 1][col + 1],
                          board[row + 2][col + 2],
                          board[row + 3][col + 3],
                          board[row + 4][col + 4])
                    ) {
                return 1;
            }
        }
    }
    return 0;
}

int SlopeFive1() {
    for (register int row = 4; row <= 19; row++) {
        for (register int col = 0; col <= 14; col++) {
            if (JudgeFive(board[row][col],
                          board[row - 1][col + 1],
                          board[row - 2][col + 2],
                          board[row - 3][col + 3],
                          board[row - 4][col + 4])
                    ) {
                return 1;
            }
        }
    }
    return 0;
}
