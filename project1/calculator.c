#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10005

enum Type { Error, Int, Double, Variable, Operator };

typedef struct value {
  enum Type type;
  union {
    char NAME[32];
    int INT;
    double DOUBLE;
  } generics;
} Value;

typedef struct assignment {
  char key[32];
  Value value;
} Assignment;

typedef struct stack {
  int top;
  char data[N];
} Stack;

Assignment assignments[N];
int assignmentCnt;
Value error = {Error, {0}};
Value *ptrError = &error;

Value Lexer(const char *word);
Value Parser(Value *values, int objCnt);
Value BinaryEval(Value value1, Value value2, char operator);
void VariableAssign(char *key, Value value);
Value VariableEval(char *key);
int CheckParen(const Value *values, int objCnt);
Value *MainOperator(Value *values, int objCnt);
Value *MinusSupport(Value *values, int objCnt);
void Output(Value result);

int main() {
  // Lexcialize
  Value values[N];
  char *buf = (char *)malloc(sizeof(char) * N);

  int objCnt = 0;
  for (; scanf("%s", buf) != -1;) {
    if (getchar() != '\n') {
      // printf("DEBUG:Continuing\n");
      values[objCnt] = Lexer(buf);
      // printf("DEBUG:TokenType:%d\n", values[objCnt].type);
      objCnt++;
    } else {
      // printf("DEBUG:Nextline\n");
      values[objCnt] = Lexer(buf);
      // printf("DEBUG:TokenType:%d\n", values[objCnt].type);
      objCnt++;
      // Parse && Evaluate
      Value result = Parser(values, objCnt);
      // Output
      Output(result);
      objCnt = 0;
    }
  }
  return 0;
}

Value VariableEval(char *key) {
  // Search
  // Value error = {Error, {0}};
  for (int i = 0; i < assignmentCnt; i++) {
    if (strcmp(key, assignments[i].key) == 0) {
      return assignments[i].value;
    }
  }
  // printf("DEBUG:EvalError\n");
  return error;
}
void VariableAssign(char *key, Value value) { // Value could also be variable
  // Preprocess value
  if (value.type == Variable) {
    value = VariableEval(value.generics.NAME);
  }
  // Modify
  for (int i = 0; i < assignmentCnt; i++) {
    if (strcmp(key, assignments[i].key) == 0) {
      assignments[i].value = value;
      return;
    }
  }
  // Add
  strcpy(assignments[assignmentCnt].key, key);
  assignments[assignmentCnt].value = value;
  assignmentCnt++;
  return;
}

void Output(Value result) {
  switch (result.type) {
  case Double:
    printf("%f\n", result.generics.DOUBLE);
    return;
  case Int:
    printf("%d\n", result.generics.INT);
    return;
  case Variable: {
    Value tmpAns = VariableEval(result.generics.NAME);
    if (tmpAns.type == Int) {
      printf("%d\n", tmpAns.generics.INT);
      return;
    } else if (tmpAns.type == Double) {
      printf("%f\n", tmpAns.generics.DOUBLE);
      return;
    }
  }
  case Error:
    printf("Error\n");
    return;
  case Operator:
    printf("Error\n");
    return;
  }
}

Value Lexer(const char *word) {
  Value result = {Error, {0}};
  int length = strlen(word);
  // Operator
  if (strcmp(word, "+") == 0 || strcmp(word, "-") == 0 ||
      strcmp(word, "*") == 0 || strcmp(word, "/") == 0 ||
      strcmp(word, "=") == 0 || strcmp(word, "(") == 0 ||
      strcmp(word, ")") == 0) {
    result.type = Operator;
    strcpy(result.generics.NAME, word);
    return result;
  }
  // Float
  char *ptr = strchr(word, '.');
  bool statFloat = true;
  if (word[0] == '0' && isdigit(word[1])) {
    statFloat = false;
  }

  if (ptr != NULL && ptr - word < length - 1 && ptr != word &&
      strchr(ptr + 1, '.') == NULL) {
    for (const char *sc = word; sc < ptr; sc++) {
      statFloat = statFloat && isdigit(*sc);
    }
    for (char *sc = ptr + 1; *sc != '\0'; sc++) {
      statFloat = statFloat && isdigit(*sc);
    }
  } else {
    statFloat = false;
  }
  if (statFloat) {
    result.type = Double;
    sscanf(word, "%lf", &result.generics.DOUBLE);
    return result;
  }
  // Int
  bool statInt = true;
  if (strlen(word) > 1 && word[0] == '0') {
    statInt = false;
  }
  for (int i = 0; i < length; i++) {
    statInt = statInt && isdigit(*(word + i));
  }
  if (statInt) {
    result.type = Int;
    sscanf(word, "%d", &result.generics.INT);
    return result;
  }
  // Var
  bool statVar = !isdigit(*word);
  for (int i = 0; i < length; i++) {
    statVar = statVar && (isalnum(*(word + i)) || *(word + i) == '_');
  }
  if (statVar) {
    result.type = Variable;
    strcpy(result.generics.NAME, word);
    return result;
  }
  // Lexical Error
  return result;
}

Value Parser(Value *values, int objCnt) {

  Value result = {Error, {0}};
  Value zero = {Int, {0}};
  // printf("DEBUG: %s\n", values[1].generics.NAME);
  // printf("DEBUG: %d\n", objCnt);
  if (objCnt <= 0) {
    // exit(1);
    // printf("DEBUG:PARERR\n");
    return error;
  } else if (objCnt == 1) {
    return *values;

  } else if (CheckParen(values, objCnt) == 1) {
    return Parser(values + 1, objCnt - 2);
  } else if (CheckParen(values, objCnt) == -1) {
    return error;

  } else if (MainOperator(values, objCnt) == NULL &&
             MinusSupport(values, objCnt) != NULL) {
    // printf("DEBUG:MinusIdentify\n");
    Value *ptr = MinusSupport(values, objCnt);
    // printf("DEBUG:Pos %ld\n", ptr - values);
    return BinaryEval(zero, Parser(ptr + 1, objCnt - 1), '-');

  } else {
    // Main operator resolve
    Value *ptrMainOperator = MainOperator(values, objCnt);
    if (ptrMainOperator == NULL || ptrMainOperator->type == Error) {
      // printf("DEBUG:NULL\n");
      return error;
    } else {
      // printf("DEBUG:MainopFound\n");
      char operator= ptrMainOperator->generics.NAME[0];
      // printf("DEBUG:MainOperator %c, objCnt: %d\n", operator, objCnt);
      result = BinaryEval(
          Parser(values, ptrMainOperator - values),
          Parser(ptrMainOperator + 1, objCnt - (ptrMainOperator - values) - 1),
          operator);
      // printf("DEBUG:Key: %u, Value: %f %d %c\n", result.type,
      //        result.generics.DOUBLE, result.generics.INT,
      //        result.generics.NAME[0]);
      return result;
    }
  }
}

Value *MainOperator(Value *values, int objCnt) {
  Value *ptrMainOperator = NULL;
  Stack stack = {0, {0}};
  char operator= 0;
  for (int i = 0; i < objCnt; i++) {
    if (values[i].type != Operator) {
      continue;
    }
    // Analyze operator outside the parentheses
    if (values[i].generics.NAME[0] == '(') {
      stack.data[stack.top] = '(';
      stack.top++;
    } else if (values[i].generics.NAME[0] == ')' &&
               stack.data[stack.top - 1] == '(') {
      stack.top--;
    } else if (stack.top == 0) {
      if (values[i].generics.NAME[0] == '=') { // Assignment
        if (values[i - 1].type == Variable && i == 1) {
          operator= values[i].generics.NAME[0];
          ptrMainOperator = values + i;
        } else {
          return ptrError;
        }
        break;
        // printf("DEBUG:Position: %ld\n", ptr - values);
        // printf("DEBUG:=");
      }
      if (values[i].generics.NAME[0] == '+') { // Plus
        operator= values[i].generics.NAME[0];
        ptrMainOperator = values + i;
        // printf("DEBUG:+-");
      } else if (values[i].generics.NAME[0] == '-') { // Sub
        if (i == 0 ||
            (values[i - 1].type == Operator &&
             (values[i - 1].generics.NAME[0] == '-' ||
              values[i - 1].generics.NAME[0] == '+' ||
              values[i - 1].generics.NAME[0] == '*' ||
              values[i - 1].generics.NAME[0] == '/' ||
              values[i - 1].generics.NAME[0] == '=' ||
              values[i - 1].generics.NAME[0] == '('))) { // Is minus but nor sub
        } else {
          operator= values[i].generics.NAME[0];
          ptrMainOperator = values + i;
        }
        // printf("DEBUG:+-");
      }
      if (values[i].generics.NAME[0] == '*' ||
          values[i].generics.NAME[0] == '/') { // Mul and Div
        if (operator== 0 || operator== '*' || operator== '/') {
          operator= values[i].generics.NAME[0];
          ptrMainOperator = values + i;
          // printf("DEBUG:*/");
        }
      }
    }
  }
  return ptrMainOperator;
}

Value *MinusSupport(Value *values, int objCnt) {
  Stack stack = {0, {0}};
  if ((values[0].type == Operator && values[0].generics.NAME[0] == '-') &&
      objCnt > 1) {
    return values;
  }
  for (int i = 0; objCnt >= 2 && i + 1 < objCnt; i++) {
    if (values[i].type != Operator) {
      continue;
    }
    // Analyze operator outside the parentheses
    if (values[i].generics.NAME[0] == '(') {
      stack.data[stack.top] = '(';
      stack.top++;
    } else if (values[i].generics.NAME[0] == ')' &&
               stack.data[stack.top - 1] == '(') {
      stack.top--;
    } else if (stack.top == 0) {
      if ((values[i].type == Operator && values[i].generics.NAME[0] != ')' &&
           values[i + 1].type == Operator &&
           values[i + 1].generics.NAME[0] == '-')) {
        // printf("DEBUG: Minus\n");
        return values + i + 1;
      }
    }
  }
  return NULL;
}

int CheckParen(const Value *values, int objCnt) {
  // Rule out parentheses error
  Stack stack = {0, {0}};
  for (int i = 0; i < objCnt; i++) {
    if (values[i].type != Operator) {
      continue;
    }
    if (values[i].generics.NAME[0] == '(') {
      stack.data[stack.top] = '(';
      stack.top++;
    } else if (values[i].generics.NAME[0] == ')' && stack.top == 0) {
      return -1;
    } else if (values[i].generics.NAME[0] == ')' &&
               stack.data[stack.top - 1] == '(') {
      stack.top--;
    }
  }
  // Parenthesis error abortion
  if (stack.top != 0) {
    return -1;
  }
  // Absolute outer parentheses assertion
  for (int i = 1; i < objCnt - 1; i++) {
    if (values[i].type != Operator) {
      continue;
    }
    if (values[i].generics.NAME[0] == '(') {
      stack.data[stack.top] = '(';
      stack.top++;
    } else if (values[i].generics.NAME[0] == ')' &&
               stack.data[stack.top - 1] == '(') {
      stack.top--;
    }
  }
  // Outer parentheses judgement
  if (stack.top == 0 && values[0].generics.NAME[0] == '(' &&
      values[objCnt - 1].generics.NAME[0] == ')') {
    return 1;
  } else {
    return 0;
  }
}

Value BinaryEval(Value value1, Value value2, char operator) {
  Value result = {Error, {0}};
  // Value error = {Error, {0}};
  double token1Promotion = 0;
  double token2Promotion = 0;

  if (value2.type == Variable) {
    value2 = VariableEval(value2.generics.NAME);
  }

  // Error Handling

  if (value1.type == Error || value2.type == Error || value1.type == Operator ||
      value2.type == Operator) {
    return error;

  } else if (operator== '=' && value1.type == Variable) {
    VariableAssign(value1.generics.NAME, value2);
    return value2;

    // Promotion
  }
  if (value1.type == Variable) {
    value1 = VariableEval(value1.generics.NAME);
  }
  if (value1.type == Error || value2.type == Error || value1.type == Operator ||
      value2.type == Operator) {
    return error;
  }
  if (value1.type != value2.type) {
    if (value1.type == Int) {
      token1Promotion = value1.generics.INT;
      token2Promotion = value2.generics.DOUBLE;
    } else if (value2.type == Int) {
      token1Promotion = value1.generics.DOUBLE;
      token2Promotion = value2.generics.INT;
    }
    result.type = Double;
    switch (operator) {
    case '+':
      result.generics.DOUBLE = token1Promotion + token2Promotion;
      break;
    case '-':
      result.generics.DOUBLE = token1Promotion - token2Promotion;
      break;
    case '*':
      result.generics.DOUBLE = token1Promotion * token2Promotion;
      break;
    case '/':
      result.generics.DOUBLE = token1Promotion / token2Promotion;
      break;
    }

  } else if (value1.type == Int) {
    result.type = Int;
    switch (operator) {
    case '+':
      result.generics.INT = value1.generics.INT + value2.generics.INT;
      break;
    case '-':
      result.generics.INT = value1.generics.INT - value2.generics.INT;
      break;
    case '*':
      result.generics.INT = value1.generics.INT * value2.generics.INT;
      break;
    case '/': {
      int divisor = value2.generics.INT;
      int dividend = value1.generics.INT;
      result.generics.INT = dividend / divisor;
      break;
    }
    }
  } else if (value1.type == Double) {
    result.type = Double;
    switch (operator) {
    case '+':
      result.generics.DOUBLE = value1.generics.DOUBLE + value2.generics.DOUBLE;
      break;
    case '-':
      result.generics.DOUBLE = value1.generics.DOUBLE - value2.generics.DOUBLE;
      break;
    case '*':
      result.generics.DOUBLE = value1.generics.DOUBLE * value2.generics.DOUBLE;
      break;
    case '/':
      result.generics.DOUBLE = value1.generics.DOUBLE / value2.generics.DOUBLE;
      break;
    }
  }
  return result;
}
