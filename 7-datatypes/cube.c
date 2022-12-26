//
// Created by Ryan Dylan on 12/24/22.
//

#include <stdio.h>

int main() {
    int T, a, b, c;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &a, &b, &c);
        for (int row = 0; row < 2 * (b + c) + 1; row++) {
            for (int col = 0; col < 2 * (a + b) + 1; col++) {
                if (row + col < 2 * b || row + col > 2 * (a + b + c))
                    putchar(' ');
                else if (row < 2 * b && row + col <= 2 * (a + b)) {
                    if ((row & 1) && !(col & 1)) putchar(' ');
                    else if ((row & 1) && (col & 1)) putchar('/');
                    else if (!(row & 1) && !(col & 1)) putchar('+');
                    else if (!(row & 1) && (col & 1)) putchar('-');
                } else if (row >= 2 * b && col <= 2 * a) {
                    if ((row & 1) && (col & 1)) putchar(' ');
                    else if ((row & 1) && !(col & 1)) putchar('|');
                    else if (!(row & 1) && !(col & 1)) putchar('+');
                    else if (!(row & 1) && (col & 1)) putchar('-');
                } else {
                    if (!(row & 1) && (col & 1)) putchar(' ');
                    else if ((row & 1) && !(col & 1)) putchar('|');
                    else if (!(row & 1) && !(col & 1)) putchar('+');
                    else if ((row & 1) && (col & 1)) putchar('/');
                }
            }
            putchar('\n');
        }
    }
    return 0;
}