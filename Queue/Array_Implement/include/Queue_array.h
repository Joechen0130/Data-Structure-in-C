// queue.h
#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

// 函數宣告
void initQueue(Queue* q);
bool IsEmpty(Queue* q);
bool IsFull(Queue* q);
void enQueue(Queue* q, int data);
int deQueue(Queue* q);
void Print(Queue* q);

#endif
