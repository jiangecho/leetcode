#include <stdbool.h>
#include <stdlib.h>

//
// Created by jiangecho on 16/7/16.
//
typedef struct {
    int *value;
    int top;

} Stack;

/* Create a stack */
void stackCreate(Stack *stack, int maxSize) {
    stack->value = (int *) malloc(sizeof(int) * maxSize);
    stack->top = 0;
}

/* Push element x onto stack */
void stackPush(Stack *stack, int element) {
    int *p = stack->value;
    *(p + stack->top) = element;
    stack->top ++;

}

/* Removes the element on top of the stack */
void stackPop(Stack *stack) {
    stack->top--;
}

/* Get the top element */
int stackTop(Stack *stack) {
    return *(stack->value + stack->top - 1);

}

/* Return whether the stack is empty */
bool stackEmpty(Stack *stack) {
    return stack->top == 0;
}

/* Destroy the stack */
void stackDestroy(Stack *stack) {
    free(stack->value);
    stack->value = NULL;
    stack->top = 0;

}

