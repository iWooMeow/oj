#include <stdio.h>
#include <stdlib.h>
typedef int TElemType;

typedef struct BiNode {
  TElemType data;
  struct BiNode *lchild, *rchild;
} BiTNode, *BiTree;
BiTree i = nullptr;
static int k = 0;
void DeleteChild(BiTree T) {
  if (!T)
    return;
  if (T) {
    DeleteChild(T->lchild);
    DeleteChild(T->rchild);
    T->data = 0;
    T = NULL;
  }
}
