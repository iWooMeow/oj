#include <iostream>
#include <malloc/_malloc.h>
typedef struct Node {
  char data;
  Node *lc, *rc;
} *NodeTree;
int DeleteTree(NodeTree &t, char e, int fl) {
  if (t == NULL) {
    return 0;
  } else {
    if (t->data == e) {
      fl = 1;
    }
    int lf = DeleteTree(t->lc, e, fl);
    int rf = DeleteTree(t->rc, e, fl);
    if (fl == 1) {
      if (t->data == e) {
        t = NULL;
        return 1;
      }
      free(t);
    } else {
      if (lf == 1) {
        t->lc = NULL;
      }
      if (rf == 1) {
        t->rc = NULL;
      }
    }
  }
  return 0;
}
