// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack_linkedlist.h"


void initStack(Stack* s){
    s->top = NULL;
}
bool isEmpty(Stack* s){
    return (s->top==NULL)?true:false;
}

void push(Stack* s,int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    if(s->top==NULL){
        s->top = temp;
        return;
    }
    temp->next = s->top;
    s->top = temp;
}
void Print(Stack* s){
    node* current = s->top;
    while(current){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int pop(Stack* s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        int data = s->top->data;
        s->top = s->top->next;
        return data;
    }
}