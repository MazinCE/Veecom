#include "evaluator.h"
#include "util.h"
#include <stdlib.h>
#include <string.h>

Evaluator_t g_Evaluator;

void Evaluator_init(void)
{
    g_Evaluator.tokenCount = 0;

    Stack_reset(&(g_Evaluator.opreratorStack));
    Stack_reset(&(g_Evaluator.outputStack));

    Terminal_print("** Expression Evaluator (SYA) **\n");
    Terminal_print("> ");
}

void Evaluator_readInput(void)
{
    char key;

    while (key != 0x0A)
    {
        key = READ_BYTE(PRB) & 0x7F;

        if (!key)
        {
            continue;
        }

        if ((key != 0x20) && (g_Evaluator.tokenCount < 32))
        {
            if ((key == 0x08) && (g_Evaluator.tokenCount > 0))
            {
                g_Evaluator.tokenCount--;
            }
            else if (key != 0x0A)
            {
                g_Evaluator.inputBuffer[g_Evaluator.tokenCount++] = key;
            }
        }

        Terminal_printChar(key);
    }
}

void Evaluator_tokenize(void)
{
    for (int i = 0; i < g_Evaluator.tokenCount; ++i)
    {
        g_Evaluator.tokens[i] = Token_Create(g_Evaluator.inputBuffer[i]);
    }
}

void Evaluator_parse(void)
{
    Stack_t *operatorStack = &(g_Evaluator.opreratorStack);
    Stack_t *outputStack = &(g_Evaluator.outputStack);

    for (int i = 0; i < g_Evaluator.tokenCount; ++i)
    {
        Token_t token = g_Evaluator.tokens[i];

        if (token.type == TK_NUMBER)
        {
            Stack_push(outputStack, token.data);
        }
        else if ((1 << token.type) & TOKEN_IS_OPERATOR_CHECK_MASK)
        {
            TokenType_e topOperator = Stack_top(operatorStack);

            // While there is higher precdence operator in the stack
            while (!Stack_empty(operatorStack) &&
                   (OPERATOR_PRECDENCE[topOperator] >= OPERATOR_PRECDENCE[token.type]) &&
                   topOperator != TK_LEFT_BRAKET)
            {
                Evaluator_performOperation(topOperator);
                Stack_pop(operatorStack);
                topOperator = Stack_top(operatorStack);
            }

            Stack_push(operatorStack, token.type);
        }
        else if (token.type == TK_LEFT_BRAKET)
        {
            Stack_push(operatorStack, token.type);
        }
        else if (token.type == TK_RIGHT_BRAKET)
        {
            TokenType_e topOperator = Evaluator_getTopOperator();

            while (!Stack_empty(operatorStack) &&
                   topOperator != TK_LEFT_BRAKET)
            {
                Evaluator_performOperation(topOperator);
                topOperator = Evaluator_getTopOperator();
            }
        }
    }

    while (!Stack_empty(operatorStack))
    {
        Evaluator_performOperation(Evaluator_getTopOperator());
    }

    g_Evaluator.tokenCount = 0;
}

void Evaluator_outputResult(void)
{
    itoa(Evaluator_getTopValue(), g_Evaluator.outputBuffer, 10);
    Terminal_println(g_Evaluator.outputBuffer);

    Terminal_print("> ");
}

void Evaluator_performOperation(TokenType_e tokenType)
{
    int b = Evaluator_getTopValue();
    int a = Evaluator_getTopValue();

    int res = 0;

    switch (tokenType)
    {
    case TK_POWER:
        res = Math_pow(a, b);
        break;
    case TK_MULTIPICATION:
        res = a * b;
        break;
    case TK_DIVISION:
        res = a / b;
        break;
    case TK_ADDITION:
        res = a + b;
        break;
    case TK_SUBSTRACTION:
        res = a - b;
        break;
    default:
        break;
    }

    Stack_push(&(g_Evaluator.outputStack), res);
}

TokenType_e Evaluator_getTopOperator(void)
{
    Stack_t *operatorStack = &(g_Evaluator.opreratorStack);
    TokenType_e topOperator = Stack_top(operatorStack);
    Stack_pop(operatorStack);

    return topOperator;
}

int Evaluator_getTopValue(void)
{
    Stack_t *outputStack = &(g_Evaluator.outputStack);
    int val = Stack_top(outputStack);
    Stack_pop(outputStack);

    return val;
}
