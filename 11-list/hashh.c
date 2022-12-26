#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

const int N = 500000;

int hash(char *s) {
    int len = strlen(s);
    int ret = 0;
    for (int i = 0; i < len; i++)ret = (ret + s[i] * (i + 1)) % N;
    return ret;
}

typedef struct node {
    char *str;
    struct node *nxt;
} node;

node mapp[500005];

void add(char *strin) {
    if(strin==NULL){
        printf("bug\n");
        return;
    }
    int x = hash(strin);
    node *new = malloc(sizeof(*new));
    new->str = strin;
    new->nxt = NULL;
    node *ptr = &mapp[x];
    if(ptr==NULL){
        return;
    }
    while (ptr->nxt!=NULL) {
        ptr = ptr->nxt;
    }
    ptr->nxt = new;
}

char *strr[500005];

bool find(char *strIn) {
    int x = hash(strIn);
    node *ptr = &mapp[x];
    if (ptr->nxt == NULL) {
        return false;
    }
    ptr = ptr->nxt;
    while (ptr != NULL) {
        if (strcmp(strIn, ptr->str) == 0) {
            return true;
        }
        ptr = ptr->nxt;
    }
    return false;
}

int main() {
    
    int n, q;
    scanf("%d%d", &n, &q);
    memset(mapp, 0, sizeof mapp);
    char tmp[1005];
    for (int i = 1; i <= n; i++) {
        scanf("%s", tmp);
        strr[i] = malloc(sizeof(char)*(strlen(tmp) + 1));
        strcpy(strr[i], tmp);
        add(strr[i]);
    }
    for (int i = 1; i <= q; i++) {
        scanf("%s", tmp);
        printf("%s\n", find(tmp) ? "Yes" : "No");
    }
    return 0;
}
