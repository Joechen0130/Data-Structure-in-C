// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue_array.h"
#define MAX 10

void initQueue(Queue* q){
    q->front = 0;
    q->rear = 0;
}
bool IsEmpty(Queue* q){
    return (q->front==q->rear)?true:false;
}
bool IsFull(Queue* q){
    return (q->rear==MAX)?true:false;
}
int deQueue(Queue* q){
    if(IsEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    else{
        int data = q->items[q->front];
        q->front++;
        return data;
    }
}
void enQueue(Queue* q, int data){
    if(IsFull(q)){
        printf("Queue is full!\n");
        return;
    }
    else{
        q->items[(q->rear)++] =  data;
    }
}
void Print(Queue* q){
    for(int i=(q->front);i<(q->rear);i++){
        printf("%d->",q->items[i]);
    }
    printf("\n");
}
