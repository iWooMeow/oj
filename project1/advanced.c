
// typedef struct token {
//   enum Type Type;
//   union {
//     char c[32];
//     int i;
//     double f;
//   } word;
// } Token;

Value Lexer(char *word) {

  Value result = {{0},Error};

  int length = strlen(word);

  // Operator

  if (strcmp(word, "+") == 0 || strcmp(word, "-") == 0 ||
      strcmp(word, "*") == 0 || strcmp(word, "/") == 0 ||
      strcmp(word, "=") == 0 || strcmp(word, "(") == 0 ||
      strcmp(word, ")") == 0) {
    result.type = Operator;
    strcpy(result.val.NAME, word);
    return result;
  }

  // Float

  char *ptr = strchr(word, '.');
  bool statFloat = true;
  // printf("DEBUG:Bool:%d", ptr == NULL && strchr(ptr, '.') == NULL);
  if (ptr != NULL && ptr - word < length - 1 && ptr != word &&
      strchr(ptr + 1, '.') == NULL) {
    for (char *sc = word; sc < ptr; sc++) {
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
    sscanf(word, "%lf", &result.val.DOUBLE);
    return result;
  }

  // Int

  bool statInt = true;
  for (int i = 0; i < length; i++) {
    statInt = statInt && isdigit(*(word + i));
  }
  if (statInt) {
    result.Type = Int;
    sscanf(word, "%d", &result.val.INT);
    return result;
  }

  // Var

  bool statVar = !isdigit(*word);
  for (int i = 0; i < length; i++) {
    statVar = statVar && (isalnum(*(word + i)) || *(word + i) == '_');
  }
  if (statVar) {
    result.type = Variable;
    strcpy(result.val.NAME, word);
    return result;
  }

  // Lexical Error

  return result;
  // printf("Error(Lex)");
  // exit(0);
}

Token Lexer(char *word) {

  Token result = {Error, {0}};

  int length = strlen(word);

  // Operator

  if (strcmp(word, "+") == 0 || strcmp(word, "-") == 0 ||
      strcmp(word, "*") == 0 || strcmp(word, "/") == 0 ||
      strcmp(word, "=") == 0 || strcmp(word, "(") == 0 ||
      strcmp(word, ")") == 0) {
    result.Type = Operator;
    strcpy(result.word.c, word);
    return result;
  }

  // Float

  char *ptr = strchr(word, '.');
  bool statFloat = true;
  if (ptr != NULL && ptr - word < length - 1 && ptr != word &&
      strchr(ptr + 1, '.') == NULL) {
    for (char *sc = word; sc < ptr; sc++) {
      statFloat = statFloat && isdigit(*sc);
    }
    for (char *sc = ptr + 1; *sc != '\0'; sc++) {
      statFloat = statFloat && isdigit(*sc);
    }
  } else {
    statFloat = false;
  }
  if (statFloat) {
    result.Type = Double;
    sscanf(word, "%lf", &result.word.f);
    return result;
  }

  // Int

  bool statInt = true;
  for (int i = 0; i < length; i++) {
    statInt = statInt && isdigit(*(word + i));
  }
  if (statInt) {
    result.Type = Int;
    sscanf(word, "%d", &result.word.i);
    return result;
  }

  // Var

  bool statVar = !isdigit(*word);
  for (int i = 0; i < length; i++) {
    statVar = statVar && (isalnum(*(word + i)) || *(word + i) == '_');
  }
  if (statVar) {
    result.Type = Variable;
    strcpy(result.word.c, word);
    return result;
  }

  // Lexical Error

  return result;
  // printf("Error(Lex)");
  // exit(0);
}


