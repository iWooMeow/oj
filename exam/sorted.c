//
// Created by Ryan Dylan on 12/12/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1005

int buf[N];

int main() {
    int times = 0;
    scanf("%d", &times);
    while (times--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (register int i = 1; i <= n; i++)
            scanf("%d", &buf[i]);
        for (register int i = 1; i <= m; i++) {
            int tmp = 0;
            scanf("%d", &tmp);
            buf[0] = buf[tmp];
            for (register int j = tmp - 1; j >= 0; j--) {
                buf[j + 1] = buf[j];
            }
        }
        int status = 1;
        for (register int i = 1; i <= n - 1; i++) {
            if (buf[i] > buf[i + 1]) {
                status = 0;
                break;
            }
        }
        printf(status? "I love C programming language\n":"mayi is a good teacher\n");
    }
    return 0;
}