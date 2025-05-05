#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
    int top;
    int a[MAX_SIZE];
} stack;

bool isFull(stack* s);
bool isEmpty(stack* s);
void push(stack* s, int value);
int pop(stack* s);
void Print(stack* s);

#endif
