# Development manual for NJUSE Project 1

### Data Abstraction:
1. enum Type: Abstraction for different types of input and output.
    * Error Int Double Variable Operator
2. struct value ( typedef Value ) : Abstraction for values: tokens and expressions.
    * enum Type type.
    * union generics: char NAME[32], int INT, double DOUBLE.
3. struct assignment ( Assignment ) : Abstraction for assignment table.
    * char key[32]
    * Value value
4. struct stack ( typedef Stack ) : Abstraction for stack to address Parens.
    * int top.
    * int data[N].

### Function Abstraction:
1. Lexer: Abstraction for tokens analysis.
    * Input:
      * First Arg:
        * type: char *word.
        * content: string from stdin.
    * Return Value:
      * type: Value result.
      * content: type and value of the ***token***.
2. Parser: Abstraction for expression analysis and evaluation.
    * Input:
      * First Arg:
        * type: Value *values
        * content: type and value of each ***token***.
      * Second Arg:
        * type: int objCnt.
        * content: the number of tokens.
    * Return Value:
      * type: Value result
      * content: type and value of each ***expression***.
3. Eval: Abstraction for arithmetic operation between two values.
    * Input:
      * First Arg:
        * type: Value value1
        * content: value1
      * Second Arg:
        * type: Value value2
        * content: value2
      * Third Arg:
        * type: char operator
        * content: operator
    * Return Value:
        * type: Value result
4. MoveTokens: Abstraction for move tokens array
    * Input:
      * First Arg:

  







