#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define DEBUG(x) printf("DEBUG: %d\n", (x))

typedef struct node {
    int size;
    int id;
    struct node *next;
} Node, *pNode;

int CalSize(int size);

pNode SearchAval(pNode pnode, int size);

pNode SearchLarger(pNode pnode, int size);

int main() {
    int n, q;
    char buf[5];
    int cnt = 1;
    scanf("%d%d", &n, &q);
    Node head = {
            .size = n,
            .id = 0,
            .next = NULL,
    };
    pNode phead = &head;
    for (; q > 0; q--) {
        scanf("%s", buf);
        if (strcmp(buf, "Q") == 0) {
            register pNode tmp = phead;
            printf("%d\n", cnt);
            for (; tmp != NULL; tmp = tmp->next) {
                printf("%d ", tmp->id);
            }
            putchar('\n');
        } else {
            int id, m;
            scanf("%d%d", &id, &m);
            m = CalSize(m);
            register pNode tmp = SearchAval(phead, m);
            while (tmp == NULL) {
                pNode larger = SearchLarger(phead, m);
                if (larger == NULL) {
                    abort();
                }
                pNode newNode = calloc(1, sizeof(Node));
                (larger->size)--;
                newNode->size = larger->size;
                newNode->next = larger->next;
                larger->next = newNode;
                cnt++;
                tmp = SearchAval(phead, m);
            }
            tmp->id = id;
        }
    }
    return 0;
}

int CalSize(int size) {
    int tmp = (int) (log(size) / log(2));
    if ((int) pow(2, tmp) == size) {
        return tmp;
    } else {
        return tmp + 1;
    }
}

pNode SearchAval(pNode pnode, int size) {
    for (; pnode != NULL; pnode = pnode->next) {
        if (pnode->size == size && pnode->id == 0) {
            return pnode;
        }
    }
    return NULL;
}

pNode SearchLarger(pNode pnode, int size) {
    for (; pnode != NULL; pnode = pnode->next) {
        if (pnode->size > size && pnode->id == 0) {
            return pnode;
        }
    }
    return NULL;
}
