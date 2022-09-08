#ifndef TOKEN_H
#define TOKEN_H

// Add left braket precdence

static const char OPERATORS[6] =
    {
        '^',
        '*',
        '/',
        '%',
        '+',
        '-',
};

static const int OPERATOR_PRECDENCE[7] =
    {
        4, // ^
        3, // *
        3, // /
        3, // % 
        2, // +
        2, // -
        5, // (
};

typedef enum
{
    TK_POWER = 0,
    TK_MULTIPICATION,
    TK_DIVISION,
    TK_MODULUS,
    TK_ADDITION,
    TK_SUBSTRACTION,
    TK_LEFT_BRAKET,
    TK_RIGHT_BRAKET,
    TK_NUMBER,
    TK_INVALID,
} TokenType_e;

static const TokenType_e TOKEN_IS_OPERATOR_CHECK_MASK = (1 << TK_POWER)         |
                                                        (1 << TK_MULTIPICATION) |
                                                        (1 << TK_DIVISION)      |
                                                        (1 << TK_MODULUS)       |
                                                        (1 << TK_ADDITION)      |
                                                        (1 << TK_SUBSTRACTION);

typedef struct
{
    TokenType_e type;
    int data;
} Token_t;

int Token_isNumber(char c);
int Token_findOperator(char c);
Token_t Token_Create(char c);

#endif