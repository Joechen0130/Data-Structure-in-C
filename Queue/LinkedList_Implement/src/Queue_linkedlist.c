// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct{
    node* front;
    node* rear;
}Queue;

void initQueue(Queue* q){
    q->front = NULL;
    q->rear = NULL;
}
bool isEmpty(Queue* q){
    return (q->front==NULL)?true:false;
}
void enQueue(Queue* q, int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    if(isEmpty(q)){
        temp->next=NULL;
        q->rear = temp;
        q->front = temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
}
int deQueue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty!\n");
        return -1;
    }
    else{
        int data = q->front->data;
        q->front = q->front->next;
        return data;
    }
}
void Print(Queue* q){
    node* current = q->front;
    while(current){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    Queue q;
    initQueue(&q);
    for(int i=0;i<20;i++){
        enQueue(&q, i);
        Print(&q);
    }
    for(int i=0;i<30;i++){
        printf("data:%d\n",deQueue(&q));
        Print(&q);
    }
    return 0;
}