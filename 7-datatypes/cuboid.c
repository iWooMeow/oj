#include <stdio.h>

void Paint(int T, int cubic[][3]);

int main() {
  int T;
  scanf("%d", &T);
  int cubic[T][3];
  for (int i = 0; i < T; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &cubic[i][j]);
    }
  }
  Paint(T, cubic);
  return 0;
}

void Paint(int T, int cubic[][3]) {
  for (int i = 0; i < T - 1; i++) {

    // For each cubic

    if (cubic[i][1] <= cubic[i][2]) {

      // Print the top Angle

      for (int k = 0; k < cubic[i][1]; k++) {
        for (int j = 0; j < 2 * cubic[i][1] - 2 * k; j++) {
          printf(" ");
        }
        for (int j = 0; j < cubic[i][0]; j++) {
          printf("+-");
        }
        printf("+");
        for (int j = 0; j < k; j++) {
          printf(" +");
        }
        putchar('\n');
        for (int j = 0; j < 2 * cubic[i][1] - 1 - 2 * k; j++) {
          printf(" ");
        }
        for (int j = 0; j < cubic[i][0]; j++) {
          printf("/ ");
        }
        for (int j = 0; j < k + 1; j++) {
          printf("/|");
        }
        putchar('\n');
      }
      for (int j = 0; j < cubic[i][0]; j++) {
        printf("+-");
      }
      printf("+");
      for (int k = 0; k < cubic[i][1]; k++) {
        printf(" +");
      }
      putchar('\n');

      // Paint the front panel

      for (int k = 0; k < cubic[i][2] - cubic[i][1]; k++) {
        for (int j = 0; j < cubic[i][0]; j++) {
          printf("| ");
        }

        printf("|");
        for (int j = 0; j < cubic[i][1]; j++) {
          printf("/|");
        }
        putchar('\n');
        for (int j = 0; j < cubic[i][0]; j++) {
          printf("+-");
        }
        printf("+");
        for (int k = 0; k < cubic[i][1]; k++) {
          printf(" +");
        }
        putchar('\n');
      }

      // Paint the bottom part

      for (int k = cubic[i][1] - 1; k >= 0; k--) {
        for (int j = 0; j < cubic[i][0]; j++) {
          printf("| ");
        }
        for (int j = 0; j < k + 1; j++) {
          printf("|/");
        }
        putchar('\n');
        for (int j = 0; j < cubic[i][0]; j++) {
          printf("+-");
        }
        printf("+");
        for (int j = 0; j < k; j++) {
          printf(" +");
        }
        putchar('\n');
      }
      printf("\b");

    } else { // Width > Height

      // Print the top Angle

      for (int k = 0; k < cubic[i][2]; k++) {
        for (int j = 0; j < 2 * cubic[i][1] - 2 * k; j++) {
          printf(" ");
        }
        for (int j = 0; j < cubic[i][0]; j++) {
          printf("+-");
        }
        printf("+");
        for (int j = 0; j < k; j++) {
          printf(" +");
        }
        putchar('\n');
        for (int j = 0; j < 2 * cubic[i][1] - 1 - 2 * k; j++) {
          printf(" ");
        }
        for (int j = 0; j < cubic[i][0]; j++) {
          printf("/ ");
        }
        for (int j = 0; j < k + 1; j++) {
          printf("/|");
        }
        putchar('\n');
      }

      // Paint the front panel

      for (int k = 0; k < cubic[i][1] - cubic[i][2]; k++) {
        for (int j = 0; j < 2 * cubic[i][1] - 2 * k - cubic[i][2] * 2; j++) {
          printf(" ");
        }
        for (int j = 0; j < cubic[i][0]; j++) {
          printf("+-");
        }
        printf("+");
        for (int k = 0; k < cubic[i][2]; k++) {
          printf(" +");
        }
        putchar('\n');
        for (int j = 0; j < 2 * cubic[i][1] - 2 * k - cubic[i][2] * 2 - 1;
             j++) {
          printf(" ");
        }
        for (int j = 0; j < cubic[i][0]; j++) {
          printf("/ ");
        }
        for (int j = 0; j < cubic[i][2]; j++) {
          printf("/|");
        }
        printf("/");
        putchar('\n');
      }

      // Paint the bottom part

      for (int k = cubic[i][2] - 1; k >= 0; k--) {
        for (int j = 0; j < cubic[i][0]; j++) {
          printf("+-");
        }
        printf("+");
        for (int j = 0; j < k + 1; j++) {
          printf(" +");
        }
        putchar('\n');
        for (int j = 0; j < cubic[i][0]; j++) {
          printf("| ");
        }
        for (int j = 0; j < k + 1; j++) {
          printf("|/");
        }
        putchar('\n');
      }
      for (int j = 0; j < cubic[i][0]; j++) {
        printf("+-");
      }
      printf("+");
      putchar('\n');
    }
  }
      if (cubic[T-1][1] <= cubic[T-1][2]) {

      // Print the top Angle

      for (int k = 0; k < cubic[T-1][1]; k++) {
        for (int j = 0; j < 2 * cubic[T-1][1] - 2 * k; j++) {
          printf(" ");
        }
        for (int j = 0; j < cubic[T-1][0]; j++) {
          printf("+-");
        }
        printf("+");
        for (int j = 0; j < k; j++) {
          printf(" +");
        }
        putchar('\n');
        for (int j = 0; j < 2 * cubic[T-1][1] - 1 - 2 * k; j++) {
          printf(" ");
        }
        for (int j = 0; j < cubic[T-1][0]; j++) {
          printf("/ ");
        }
        for (int j = 0; j < k + 1; j++) {
          printf("/|");
        }
        putchar('\n');
      }
      for (int j = 0; j < cubic[T-1][0]; j++) {
        printf("+-");
      }
      printf("+");
      for (int k = 0; k < cubic[T-1][1]; k++) {
        printf(" +");
      }
      putchar('\n');

      // Paint the front panel

      for (int k = 0; k < cubic[T-1][2] - cubic[T-1][1]; k++) {
        for (int j = 0; j < cubic[T-1][0]; j++) {
          printf("| ");
        }

        printf("|");
        for (int j = 0; j < cubic[T-1][1]; j++) {
          printf("/|");
        }
        putchar('\n');
        for (int j = 0; j < cubic[T-1][0]; j++) {
          printf("+-");
        }
        printf("+");
        for (int k = 0; k < cubic[T-1][1]; k++) {
          printf(" +");
        }
        putchar('\n');
      }

      // Paint the bottom part

      for (int k = cubic[T-1][1] - 1; k >= 0; k--) {
        for (int j = 0; j < cubic[T-1][0]; j++) {
          printf("| ");
        }
        for (int j = 0; j < k + 1; j++) {
          printf("|/");
        }
        putchar('\n');
        for (int j = 0; j < cubic[T-1][0]; j++) {
          printf("+-");
        }
        printf("+");
        for (int j = 0; j < k; j++) {
          printf(" +");
        }
        putchar('\n');
      }
      printf("\b");

    } else { // Width > Height

      // Print the top Angle

      for (int k = 0; k < cubic[T-1][2]; k++) {
        for (int j = 0; j < 2 * cubic[T-1][1] - 2 * k; j++) {
          printf(" ");
        }
        for (int j = 0; j < cubic[T-1][0]; j++) {
          printf("+-");
        }
        printf("+");
        for (int j = 0; j < k; j++) {
          printf(" +");
        }
        putchar('\n');
        for (int j = 0; j < 2 * cubic[T-1][1] - 1 - 2 * k; j++) {
          printf(" ");
        }
        for (int j = 0; j < cubic[T-1][0]; j++) {
          printf("/ ");
        }
        for (int j = 0; j < k + 1; j++) {
          printf("/|");
        }
        putchar('\n');
      }

      // Paint the front panel

      for (int k = 0; k < cubic[T-1][1] - cubic[T-1][2]; k++) {
        for (int j = 0; j < 2 * cubic[T-1][1] - 2 * k - cubic[T-1][2] * 2; j++) {
          printf(" ");
        }
        for (int j = 0; j < cubic[T-1][0]; j++) {
          printf("+-");
        }
        printf("+");
        for (int k = 0; k < cubic[T-1][2]; k++) {
          printf(" +");
        }
        putchar('\n');
        for (int j = 0; j < 2 * cubic[T-1][1] - 2 * k - cubic[T-1][2] * 2 - 1;
             j++) {
          printf(" ");
        }
        for (int j = 0; j < cubic[T-1][0]; j++) {
          printf("/ ");
        }
        for (int j = 0; j < cubic[T-1][2]; j++) {
          printf("/|");
        }
        printf("/");
        putchar('\n');
      }

      // Paint the bottom part

      for (int k = cubic[T-1][2] - 1; k >= 0; k--) {
        for (int j = 0; j < cubic[T-1][0]; j++) {
          printf("+-");
        }
        printf("+");
        for (int j = 0; j < k + 1; j++) {
          printf(" +");
        }
        putchar('\n');
        for (int j = 0; j < cubic[T-1][0]; j++) {
          printf("| ");
        }
        for (int j = 0; j < k + 1; j++) {
          printf("|/");
        }
        putchar('\n');
      }
      for (int j = 0; j < cubic[T-1][0]; j++) {
        printf("+-");
      }
      printf("+");
      // putchar('\n');
    }

}
