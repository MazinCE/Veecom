#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 32

typedef struct
{
    int top;
    int data[STACK_SIZE];
} Stack_t;

void Stack_reset(Stack_t *stack);
int Stack_empty(Stack_t *stack);
int Stack_top(Stack_t *stack);
void Stack_push(Stack_t *stack, int data);
void Stack_pop(Stack_t *stack);

#endif