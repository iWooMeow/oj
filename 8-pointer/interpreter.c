#include <stdio.h>
#include <stdlib.h>

int main() {
  void *input = malloc(sizeof(int));
  scanf("%x", (unsigned *)input);
  printf("%d\n", *(int *)input);
  printf("%u\n", *(unsigned int *)input);
  printf("%.6f\n", *(float *)input);
  printf("%.3e\n", *(float *)input);
  free(input);
  return 0;
}
