//
// Created by Ryan Dylan on 12/17/22.
//

#ifndef OJ_LINKEDLIST_H
#define OJ_LINKEDLIST_H

#endif //OJ_LINKEDLIST_H

typedef struct node {
    int val;
    struct node *next;
} Node;

typedef struct link {
    Node *head;
    Node *tail;
} Link;

void Append(Link *, int);

void Remove(Link *, int);

Node *ScanList(Link *, int);

void Free(Link *);