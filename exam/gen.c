//
// Created by Ryan Dylan on 12/23/22.
//

#include <stdio.h>
#include <unistd.h>

int main() {
    FILE *fp;
    fp = fopen("test.in", "w+");
    fprintf(fp, "3 3 52\n");
    int cnt = 0;
    for (int a = 1; a < 4; a++) {
        for (int b = 1; b < 4; b++) {
            for (int c = 1; c < 4; c++) {
                for (int d = 1; d < 4; d++) {
                    for (int e = 1; e < 4; e++) {
                        for (int f = 1; f < 4; f++) {
                            for (int g = 1; g < 4; g++) {
                                for (int h = 1; h < 4; h++) {
//                                    for (int i = 1; i < 4; i++) {
                                    if (c >= a && d >= b && g >= e && h >= f && c - a == g - e && h - f == d - b
                                        && ((e > c + 1 || a > g + 1) || (f > d + 1 || b > h + 1))) {
                                        fprintf(fp, "%d %d %d %d %d %d %d %d %d\n", a, b, c, d,
                                                e, f, g, h, 2);
                                        cnt++;
//                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    }
    printf("%d", cnt);


    return 0;
}
