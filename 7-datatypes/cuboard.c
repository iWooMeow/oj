#include <stdio.h>
#include <string.h>

char board[10005][10005];

void Paint(int i, const int cubic[][3]);
void Output(int rowM, int colM);

int main() {
  int T;
  scanf("%d", &T);
  int cubic[T][3];
  memset(board, ' ', sizeof(board));
  for (int i = 0; i < T; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &cubic[i][j]);
    }
  }
  for (int i = 0; i < T; i++) {
    Paint(i, cubic);
    Output(cubic[i][2] * 2 + cubic[i][1] * 2 + 1,
           cubic[i][1] * 2 + cubic[i][0] * 2 + 1);
    memset(board, ' ', sizeof(board));
  }
  return 0;
}

void Paint(int i, const int cubic[][3]) {
  int length = cubic[i][0];
  int width = cubic[i][1];
  int height = cubic[i][2];
  if (height >= width) {

    // Top Side

    for (int row = 0; row < 2 * width; row += 2) {
      for (int col = 0; col < 2 * length; col += 2) {
        board[row][col - row + width * 2] = '+';
        board[row][col - row + width * 2 + 1] = '-';
      }
      board[row][2 * length - row + width * 2] = '+';
      for (int col = 0; col <= 2 * row; col += 2) {
        // board[row][2 * length + width - row] = ' ';
        board[row][2 * length + width * 2 - row + 2 + col] = '+';
      }
      for (int col = 0; col < 2 * length; col += 2) {
        board[row + 1][col - row + width * 2 - 1] = '/';
        // board[row + 1][col - row + width] = ' ';
      }
      for (int col = 0; col <= 2 * row; col += 2) {
        board[row + 1][2 * length + width * 2 - row - 1 + col] = '/';
        board[row + 1][2 * length + width * 2 - row + col] = '|';
      }
    }

    // Edge

    for (int col = 0; col < 2 * length; col += 2) {
      board[2 * width][col] = '+';
      board[2 * width][col + 1] = '-';
    }
    board[2 * width][2 * length] = '+';
    for (int col = 0; col < 2 * width; col += 2) {
      board[2 * width][2 * length + col + 2] = '+';
    }

    // Front

    for (int row = 0; row < 2 * (height - width); row += 2) {
      for (int col = 0; col < 2 * length; col += 2) {
        board[row + 2 * width + 1][col] = '|';
      }
      for (int col = 0; col < 2 * width; col += 2) {
        board[row + 2 * width + 1][col + 2 * length] = '|';
        board[row + 2 * width + 1][col + 2 * length + 1] = '/';
      }
      board[row + 2 * width + 1][2 * width + 2 * length] = '|';
      for (int col = 0; col < 2 * length; col += 2) {
        board[row + 2 * width + 2][col] = '+';
        board[row + 2 * width + 2][col + 1] = '-';
      }
      board[row + 2 * width + 2][2 * length] = '+';
      for (int col = 0; col < 2 * width; col += 2) {
        board[row + 2 * width + 2][col + 2 * length + 2] = '+';
      }
    }

    // Bottom

    for (int row = 0; row < 2 * width; row += 2) {
      for (int col = 0; col < 2 * length; col += 2) {
        board[row + 2 * height + 1][col] = '|';
      }
      for (int col = 0; col < 2 * width - row; col += 2) {
        board[row + 2 * height + 1][col + 2 * length] = '|';
        board[row + 2 * height + 1][col + 2 * length + 1] = '/';
      }
      // board[row + 2 * width + 1][2 * width + 2 * length] = '|';
      for (int col = 0; col < 2 * length; col += 2) {
        board[row + 2 * height + 2][col] = '+';
        board[row + 2 * height + 2][col + 1] = '-';
      }
      board[row + 2 * height + 2][2 * length] = '+';
      for (int col = 0; col < 2 * width - row - 2; col += 2) {
        board[row + 2 * height + 2][col + 2 * length + 2] = '+';
      }
    }

  } else {

    // Top Side

    for (int row = 0; row < 2 * height; row += 2) {
      for (int col = 0; col < 2 * length; col += 2) {
        board[row][col - row + width * 2] = '+';
        board[row][col - row + width * 2 + 1] = '-';
      }
      board[row][2 * length - row + width * 2] = '+';
      for (int col = 0; col <= 2 * row; col += 2) {
        // board[row][2 * length + width - row] = ' ';
        board[row][2 * length + width * 2 - row + 2 + col] = '+';
      }
      for (int col = 0; col < 2 * length; col += 2) {
        board[row + 1][col - row + width * 2 - 1] = '/';
        // board[row + 1][col - row + width] = ' ';
      }
      for (int col = 0; col <= 2 * row; col += 2) {
        board[row + 1][2 * length + width * 2 - row - 1 + col] = '/';
        board[row + 1][2 * length + width * 2 - row + col] = '|';
      }
    }

    // Edge

    for (int col = 0; col < 2 * length; col += 2) {
      board[2 * height][col + 2 * width - 2 * height] = '+';
      board[2 * height][col + 1 + 2 * width - 2 * height] = '-';
    }
    board[2 * height][2 * length + 2 * width - 2 * height] = '+';
    for (int col = 0; col < 2 * height; col += 2) {
      board[2 * height][2 * width - 2 * height + 2 * length + col + 2] = '+';
    }

    // Front

    for (int row = 0; row < 2 * (width - height); row += 2) {
      for (int col = 0; col < 2 * length; col += 2) {
        board[row + 2 * height + 1][2 * width - 2 * height + col - row - 1] =
            '/';
      }
      for (int col = 0; col <= 2 * height; col += 2) {
        board[row + 2 * height + 1]
             [2 * length + 2 * width - 2 * height + col - row - 1] = '/';
        board[row + 2 * height + 1]
             [2 * length + 2 * width - 2 * height + col - row] = '|';
      }
      board[row + 2 * height + 1][2 * length + 2 * width - row] = ' ';
      for (int col = 0; col < 2 * length; col += 2) {
        board[row + 2 * height + 2][2 * width - 2 * height + col - row - 2] =
            '+';
        board[row + 2 * height + 2][2 * width - 2 * height + col - row - 1] =
            '-';
      }
      board[row + 2 * height + 2]
           [2 * width - 2 * height + 2 * length - row - 2] = '+';
      for (int col = 0; col < 2 * height; col += 2) {
        board[row + 2 * height + 2]
             [2 * length + 2 * width - 2 * height + col - row] = '+';
      }
    }

    // Bottom

    for (int row = 0; row < 2 * width; row += 2) {
      for (int col = 0; col < 2 * length; col += 2) {
        board[row + 2 * width + 1][col] = '|';
      }
      for (int col = 0; col < 2 * height - row; col += 2) {
        board[row + 2 * width + 1][col + 2 * length] = '|';
        board[row + 2 * width + 1][col + 2 * length + 1] = '/';
      }
      // // board[row + 2 * width + 1][2 * width + 2 * length] = '|';
      for (int col = 0; col < 2 * length; col += 2) {
        board[row + 2 * width + 2][col] = '+';
        board[row + 2 * width + 2][col + 1] = '-';
      }
      board[row + 2 * width + 2][2 * length] = '+';
      for (int col = 0; col < 2 * height - row - 2; col += 2) {
        board[row + 2 * width + 2][col + 2 * length + 2] = '+';
      }
    }
  }
}

void Output(int rowM, int colM) {
  for (int row = 0; row < rowM; row++) {
    for (int col = 0; col < colM; col++) {
      printf("%c", board[row][col]);
    }
    putchar('\n');
  }
}
