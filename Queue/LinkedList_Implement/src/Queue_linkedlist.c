// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue_linkedlist.h"

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue* q) {
    return (q->front == NULL);
}

void enQueue(Queue* q, int data) {
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

int deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    } else {
        node* temp = q->front;
        int data = temp->data;
        q->front = q->front->next;
        free(temp);
        if (q->front == NULL) {
            q->rear = NULL;
        }
        return data;
    }
}

void Print(Queue* q) {
    node* current = q->front;
    while (current) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}