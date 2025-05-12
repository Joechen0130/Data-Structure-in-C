// queue.h
#ifndef QUEUE_LINKEDLIST_H
#define QUEUE_LINKEDLIST_H

#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct {
    node* front;
    node* rear;
} Queue;

void initQueue(Queue* q);
bool isEmpty(Queue* q);
void enQueue(Queue* q, int data);
int deQueue(Queue* q);
void Print(Queue* q);

#endif
