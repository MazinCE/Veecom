#include "token.h"

Token_t Token_Create(char c)
{
    Token_t token;
    token.type = TK_INVALID;

    if (Token_isNumber(c))
    {
        token.type = TK_NUMBER;
        token.data = c - '0';
    }
    else if (c == '(')
    {
        token.type = TK_LEFT_BRAKET;
    }
    else if (c == ')')
    {
        token.type = TK_RIGHT_BRAKET;
    }
    else
    {
        int operatorIndex = Token_findOperator(c);

        if (operatorIndex >= TK_POWER)
        {
            token.type = operatorIndex;
        }
    }

    return token;
}

int Token_isNumber(char c)
{
    return c >= '0' && c <= '9';
}

int Token_findOperator(char c)
{
    for (int i = 0; i < 6; ++i)
    {
        if (OPERATORS[i] == c)
        {
            return i;
        }
    }

    return -1;
}
