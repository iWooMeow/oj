#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIGIT 10002

typedef struct _bigInt {
  int digit[DIGIT];
} bigInt;

// when declaration the element num is different from index num

bigInt add(bigInt a, bigInt b);
bigInt sub(bigInt a, bigInt b);
bigInt mul(bigInt a, bigInt b);
bigInt divi(bigInt dividend, bigInt divisor);

bigInt mulModDigitMul(bigInt a, int time);
bigInt mulModMove(bigInt a, int time);

bigInt read();
bigInt write(bigInt a, bigInt b);
void output(bigInt result);

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    bigInt a = read();
    char operator;
    scanf(" %c", &operator);
    bigInt b = read();
    bigInt result;
    switch (operator) {
    case '+':
      result = add(a, b);
      break;
    case '-':
      result = sub(a, b);
      break;
    case '*':
      result = mul(a, b);
      break;
    case '/':
      result = divi(a, b);
      break;
      // default:
      //   assert(0);
    }
    output(result);
  }
  return 0;
}
// switch must add break to EACH case
bigInt read() {
  char buffer[DIGIT - 1] = {0};
  bigInt read = {{0}};
  scanf("%s", buffer);
  int len, bufi, arrayi;
  len = strlen(buffer);
  // strlen not include \0
  arrayi = 0;
  for (bufi = len - 1; bufi >= 0; bufi--) {
    read.digit[arrayi] = buffer[bufi] - '0';
    arrayi++;
  }
  return read;
}
// init value array=0 should be outside for loop

bigInt add(bigInt a, bigInt b) {
  bigInt result = {{0}};
  int i;
  for (i = 0; i <= DIGIT - 1; i++) {
    if (result.digit[i] + a.digit[i] + b.digit[i] > 9) {
      result.digit[i] = result.digit[i] + a.digit[i] + b.digit[i] - 10;
      result.digit[i + 1]++;
    } else {
      result.digit[i] = a.digit[i] + b.digit[i] + result.digit[i];
    }
  }
  return result;
}

bigInt sub(bigInt a, bigInt b) {
  bigInt result = {{0}};
  int i;
  for (i = 0; i <= DIGIT - 1; i++) {
    if (result.digit[i] + a.digit[i] - b.digit[i] < 0) {
      result.digit[i] = result.digit[i] + 10 + a.digit[i] - b.digit[i];
      result.digit[i + 1]--;
    } else {
      result.digit[i] = a.digit[i] - b.digit[i] + result.digit[i];
    }
  }

  return result;
}
bigInt mul(bigInt a, bigInt b) {
  bigInt temp = {{0}}, result = {{0}};
  int i;
  for (i = 0; i <= DIGIT - 1; i++) {
    temp = mulModDigitMul(b, a.digit[i]);
    result = add(result, mulModMove(temp, i));
  }
  return result;
}

bigInt divi(bigInt a, bigInt b) {
  bigInt result;
  return result;
}
bigInt mulModDigitMul(bigInt a, int time) {
  bigInt result = {{0}};
  for (; time >= 1; time--) {
    result = add(a, result);
  }
  return result;
}
bigInt mulModMove(bigInt a, int time) {
  bigInt result = {{0}};
  int i;
  for (i = DIGIT - time - 1; i >= 0; i--) {
    result.digit[i + time] = a.digit[i];
  }
  return result;
}
void output(bigInt result) {
  int i;
  for (i = DIGIT - 1; i >= 0; i--) {
    if (result.digit[i] != 0) {
      break;
    }
  }
  for (; i >= 0; i--) {
    printf("%d", result.digit[i]);
  }
}
// for loop simple style
