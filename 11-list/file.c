#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20
#define isLeaf(T) ((T) != NULL && (T)->left == NULL && (T)->right == NULL)
#define isFull(T) ((T) != NULL && (T)->left != NULL && (T)->right != NULL)
#define DEBUG puts("DEBUG")

typedef struct tree {
  char label[N];
  struct tree *left;
  struct tree *right;
} Tree;

Tree *Search(Tree *tree, char *label);
Tree *AddTree(Tree *tree, char *label);
void RemoveTree(Tree *head, char *label);
void FreeTree(Tree *tree);
int Leaves(Tree *tree);
Tree *ScanTree(Tree *root, char *label);

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  char filename[N];
  char parent[N];
  Tree root = {.label = {0}, .left = NULL, .right = NULL};
  Tree *rootPtr = &root;
  for (int i = 0; i < n; i++) {
    scanf("%s%s", filename, parent);
    if (strcmp(parent, "~~~") == 0) {
      strcpy(root.label, filename);
    } else {
      AddTree(Search(rootPtr, parent), filename);
    }
  }
  char buf1[N];
  char buf2[N];
  for (int i = 0; i < q; i++) {
    scanf("%s%s", buf1, buf2);
    if (strcmp(buf1, "query") == 0) {
      printf("%d\n", Leaves(Search(rootPtr, buf2)));
    } else if (strcmp(buf1, "remove") == 0) {
      RemoveTree(rootPtr, buf2);
    }
  }
  return 0;
}

Tree *ScanTree(Tree *root, char *label) {
  if (isLeaf(root)) {
    return NULL;
  }

  if (isFull(root)) {
    if (strcmp(root->left->label, label) == 0) {
      return root->left;
    } else if (strcmp(root->right->label, label) == 0) {
      return root->right;
    } else {
      Tree *tmp = ScanTree(root->left, label);
      if (tmp != NULL) {
        return tmp;
      } else {
        return ScanTree(root->right, label);
      }
    }
  } else {
    if (strcmp(root->left->label, label) == 0) {
      return root->left;
    }
    return ScanTree(root->left, label);
  }
}

void FreeTree(Tree *tree) {
  if (tree == NULL) {
    return;
  } else if (isLeaf(tree)) {
    free(tree);
  } else if (isFull(tree)) {
    FreeTree(tree->left);
    FreeTree(tree->right);
  } else {
    FreeTree(tree->left);
    free(tree);
  }
}

Tree *Search(Tree *tree, char *label) {
  if (tree == NULL) {
    return NULL;
  } else if (strcmp(tree->label, label) == 0) {
    return tree;
  } else if (isLeaf(tree)) {
    return NULL;
  } else if (isFull(tree)) {
    Tree *res = Search(tree->left, label);
    if (res != NULL) {
      return res;
    } else {
      return Search(tree->right, label);
    }
  } else {
    return Search(tree->left, label);
  }
}

void RemoveTree(Tree *tree, char *label) {
  if (tree == NULL) {
    return;
  } else if (isLeaf(tree)) {
    return;
  } else if (isFull(tree)) {
    if (strcmp(tree->left->label, label) == 0) {
      FreeTree(tree->left);
      tree->left = tree->right;
      tree->right = NULL;
      return;
    } else if (strcmp(tree->right->label, label) == 0) {
      FreeTree(tree->right);
      tree->right = NULL;
      return;
    }
    RemoveTree(tree->left, label);
    RemoveTree(tree->right, label);
  } else {
    if (strcmp(tree->left->label, label) == 0) {
      FreeTree(tree->left);
      tree->left = NULL;
      return;
    }
    RemoveTree(tree->left, label);
  }
}

Tree *AddTree(Tree *node, char *label) {
  Tree *newTree = calloc(1, sizeof(Tree));
  strcpy(newTree->label, label);
  newTree->left = NULL;
  newTree->right = NULL;
  if (node == NULL) {
    return NULL;
  } else if (isFull(node)) {
    return NULL;
  } else if (node->left == NULL) {
    node->left = newTree;
  } else {
    node->right = newTree;
  }
  return newTree;
}

int Leaves(Tree *tree) {
  if (tree == NULL) {
    return 0;
  } else if (isLeaf(tree)) {
    return 1;
  } else if (isFull(tree)) {
    return 1 + Leaves(tree->left) + Leaves(tree->right);
  } else {
    return 1 + Leaves(tree->left);
  }
}
