#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int maximum = 100;
  int attempts = 8;
  printf(
      "Lets guess the secret number.\n"
      "If you input is larger than the number ,you'll be alerted.So is "
      "smaller.\n"
      "The maximum number is %d and the number of attempts is limited to %d.\n",
      maximum, attempts);
  srand(time(NULL));
  int secret = rand() % maximum + 1;
  while (attempts > 0) {
    int input = 0;
    scanf("%d", &input);
    if (input > secret) {
      printf("Input is larger.\n");
    } else if (input < secret) {
      printf("Input is smaller\n");
    } else {
      printf("You win!\n");
      break;
    }
    attempts--;
  }

  return 0;
}
