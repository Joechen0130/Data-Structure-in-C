// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Queue_circular_array.h"

void initQueue(Queue* q){
    q->front = 0;
    q->rear = 0;
    q->size =0;
}
bool IsEmpty(Queue* q){
    return (q->size==0)?true:false;
}
bool IsFull(Queue* q){
    return (q->size==MAX)?true:false;
}
int deQueue(Queue* q){
    if(IsEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    else{
        int data  = q->items[q->front];
        q->front = (q->front+1)%MAX;
        q->size--;
        return  data;
    }
}
void enQueue(Queue* q, int data){
    if(IsFull(q)){
        printf("Queue is full!\n");
        return;
    }
    else{
        q->items[q->rear] = data;
        q->rear = (q->rear+1)%MAX;
        q->size++;
    }
}
void Print(Queue* q){
    for(int i=0;i<(q->size);i++){
        int index = (q->front+i)%MAX;
        printf("%d->",q->items[index]);
    }
    printf("\n");
}