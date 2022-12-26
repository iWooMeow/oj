
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

typedef struct tree {
  char label[N];
  struct tree *left;
  struct tree *right;
} Tree;

Tree Empty = {.label = {0}, NULL, NULL};

Tree *Search(Tree *tree, char *label);
void AddTree(Tree *root, Tree *toBeAdd);
int Leaves(Tree *tree);
int isEmpty(Tree *tree);
int isLeaf(Tree *tree);
Tree trees[10005];

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    memset(trees[i].label, 0, sizeof(char) * N);
    trees[i].left = &Empty;
    trees[i].right = &Empty;
  }
  char filename[N];
  char parent[N];
  for (int i = 0; i < n; i++) {
    scanf("%s%s", filename, parent);
    if (strcmp(parent, "~~~") == 0) {
      strcpy(trees[i].label, filename);
    } else {
      strcpy(trees[i].label, filename);
      Tree *parentPtr = Search(trees, parent);
      AddTree(parentPtr, trees + i);
    }
  }
  char buf1[N];
  char buf2[N];
  for (int i = 0; i < q; i++) {
    scanf("%s%s", buf1, buf2);
    if (strcmp(buf1, "query") == 0) {
      printf("%d\n", Leaves(Search(trees, buf2)));
    } else if (strcmp(buf1, "remove") == 0) {
      Tree *tmp = Search(trees, buf2);
      *tmp = Empty;
    }
  }
  return 0;
}

Tree *Search(Tree *tree, char *label) {
  if (isEmpty(tree)) {
    return &Empty;
  } else if (strcmp(tree->label, label) == 0) {
    return tree;
  } else if (isLeaf(tree)) {
    return &Empty;
  } else if (!isEmpty(tree->right)) {
    Tree *ptr1 = Search(tree->left, label);
    Tree *ptr2 = Search(tree->right, label);
    if (!isEmpty(ptr1)) {
      return ptr1;
    } else {
      return ptr2;
    }
  } else if (!isEmpty(tree->left)) {
    return Search(tree->left, label);
  }
return &Empty;
}

int isEmpty(Tree *tree) {
  if (tree->label[0] == 0) {
    return 1;
  } else {
    return 0;
  }
}
int Leaves(Tree *tree) {
  if (isEmpty(tree)) {
    return 0;
  } else if (isLeaf(tree)) {
    return 1;
  } else if (!isEmpty(tree->right)) {
    return 1 + Leaves(tree->left) + Leaves(tree->right);
  } else {
    return 1 + Leaves(tree->left);
  }
}

void AddTree(Tree *root, Tree *toBeAdd) {
  if (!isEmpty(root->left)) {
    root->right = toBeAdd;
  } else {
    root->left = toBeAdd;
  }
}

int isLeaf(Tree *tree) {
  return (tree->left == &Empty && tree->right == &Empty);
}
