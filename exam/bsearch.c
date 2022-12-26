//
// Created by Ryan Dylan on 12/22/22.
//

#include <stdlib.h>
#include <stdio.h>

int cmp(const void *p1, const void *p2) {
    int a = *(int *) p1;
    int b = *(int *) p2;
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int *buf = malloc(n * sizeof(int));
    for (register int i = 0; i < n; i++) {
        scanf("%d", &buf[i]);
    }
    for (register int i = 0; i < q; i++) {
        int key;
        scanf("%d", &key);
        int *ptr = bsearch(&key, buf, n, sizeof(int), cmp);
        if (ptr == NULL) {
            puts("-1\n");
        } else {
            printf("%d\n", ptr - buf);
        }
    }

    return 0;
}

