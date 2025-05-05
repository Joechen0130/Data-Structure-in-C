// Stack_linkedlist.h

#ifndef STACK_LINKEDLIST_H
#define STACK_LINKEDLIST_H

#include <stdbool.h>

// 定義節點結構
typedef struct node {
    int data;
    struct node* next;
} node;

// 定義堆疊結構
typedef struct Stack {
    node* top;
} Stack;

// 函式宣告
void initStack(Stack* s);
bool isEmpty(Stack* s);
void push(Stack* s, int data);
int pop(Stack* s);
void Print(Stack* s);

#endif // STACK_LINKEDLIST_H
