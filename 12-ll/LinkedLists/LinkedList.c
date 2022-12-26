//
// Created by Ryan Dylan on 12/17/22.
//
#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>

void Append(Link *list, int val) {
    Node *pnode = calloc(1, sizeof *pnode);
    pnode->val = val;
    pnode->next = list->head;
    list->tail->next = pnode;
    list->tail = pnode;

}

Node *ScanList(Link *link, int val) {


}

void Free(Link *list) {


}



