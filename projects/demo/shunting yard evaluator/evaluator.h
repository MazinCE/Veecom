/*
Simple Shunting yard math equatuin evaluator
   * Supports single digits positive numbers only

Shunting yard algorithm

1.  While there are tokens to be read:
2.        Read a token
3.        If it's a number add it to queue
4.        If it's an operator
5.               While there's an operator on the top of the stack with greater precedence:
6.                       Pop operators from the stack onto the output queue
7.               Push the current operator onto the stack
8.        If it's a left bracket push it onto the stack
9.        If it's a right bracket
10.            While there's not a left bracket at the top of the stack:
11.                     Pop operators from the stack onto the output queue.
12.             Pop the left bracket from the stack and discard it
13. While there are operators on the stack, pop them to the queue
*/

#ifndef Evaluator_H
#define Evaluator_H

#include "stack.h"
#include "token.h"

typedef struct
{
   Stack_t outputStack;
   Stack_t opreratorStack;
   Token_t tokens[32];
   char inputBuffer[32];
   char outputBuffer[32];
   int tokenCount;

} Evaluator_t;

extern Evaluator_t g_Evaluator;

void Evaluator_init(void);
void Evaluator_readInput(void);
void Evaluator_tokenize(void);
void Evaluator_parse(void);
void Evaluator_outputResult(void);
void Evaluator_performOperation(TokenType_e tokenType);
TokenType_e Evaluator_getTopOperator(void);
int Evaluator_getTopValue(void);


#endif