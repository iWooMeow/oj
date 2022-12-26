//
// Created by Ryan Dylan on 12/23/22.
//

#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b)     \
    do {               \
        Node *tmp = a; \
        a = b;         \
        b = tmp;       \
    } while (0)

typedef long long ll;

typedef struct node {
    int val;
    struct node *right;
    struct node *below;
} Node;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    register Node *phead = malloc((m + 1) * (n + 1) * sizeof(Node));
    register Node *ext = phead;
    for (register int row = 0; row <= n; row++) {
        for (register int col = 0; col <= m; col++) {
            phead[col + (m + 1) * row].val = row * m + col;
            phead[col + (m + 1) * row].right = col == m ? NULL : &phead[col + (m + 1) * row + 1];
            phead[col + (m + 1) * row].below = row == n ? NULL : &phead[col + (row + 1) * (m + 1)];
        }
    }
    phead = &phead[1 + m];
    int x1, y1, x2, y2, x3, y3, x4, y4, a;
    int q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4, &a);
        Node *ext1 = ext;
        Node *ext2 = ext;
        for (register int row = 0; row < x1 - 1; row++)
            ext1 = ext1->below;
        for (register int col = 0; col < y1 - 1; col++)
            ext1 = ext1->right;
        for (register int row = 0; row < x3 - 1; row++)
            ext2 = ext2->below;
        for (register int col = 0; col < y3 - 1; col++)
            ext2 = ext2->right;
        Node *head1 = ext1->below->right;
        Node *head2 = ext2->below->right;

//        Node *r1 = Search(phead, x1, y2);
//        Node *d1 = Search(phead, x2, y1);
        Node *r1 = head1;
        Node *d1 = head1;
        for (register int i = 0; i < y2 - y1; i++)
            r1 = r1->right;
        for (register int i = 0; i < x2 - x1; i++)
            d1 = d1->below;

        Node *l1 = ext1->below;
        Node *u1 = ext1->right;

        Node *r2 = head2;
        Node *d2 = head2;

        for (register int i = 0; i < y2 - y1; i++)
            r2 = r2->right;
        for (register int i = 0; i < x2 - x1; i++)
            d2 = d2->below;


        Node *l2 = ext2->below;
        Node *u2 = ext2->right;

        if (x1 == 1 && y1 == 1)
            phead = head2;
        else if (x3 == 1 && y3 == 1)
            phead = head1;

        for (register int i = 0; i <= x2 - x1; i++) {
            SWAP(r1->right, r2->right);
            if (i != x2 - x1) {
                r1 = r1->below;
                r2 = r2->below;
            }
        }
        for (register int i = 0; i <= y2 - y1; i++) {
            SWAP(d1->below, d2->below);
            if (i != y2 - y1) {
                d1 = d1->right;
                d2 = d2->right;
            }
        }
        for (register int i = 0; i <= x2 - x1; i++) {
            SWAP(l1->right, l2->right);
            if (i != x2 - x1) {
                l1 = l1->below;
                l2 = l2->below;
            }
        }
        for (register int i = 0; i <= y2 - y1; i++) {
            SWAP(u1->below, u2->below);
            if (i != y2 - y1) {
                u1 = u1->right;
                u2 = u2->right;
            }
        }
        ll ans = 0;
        Node *tmp = phead;
        while (a > 1) {
            tmp = tmp->below;
            a--;
        }
        for (register int i = 0; i < m; i++) {
            ans += tmp->val;
            tmp = tmp->right;
        }
        printf("%lld\n", ans);
    }
    return 0;
}