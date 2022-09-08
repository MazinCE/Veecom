#include "stack.h"

void Stack_reset(Stack_t *stack)
{
    stack->top = -1;
}

int Stack_empty(Stack_t *stack)
{
    return stack->top < 0;
}

int Stack_top(Stack_t *stack)
{
    return stack->data[stack->top];
}

void Stack_push(Stack_t *stack, int data)
{
    if (stack->top < STACK_SIZE - 1)
    {
        stack->data[++stack->top] = data;
    }
}

void Stack_pop(Stack_t *stack)
{
    if (stack->top > -1)
    {
        stack->top--;
    }
}
