// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Stack_array.h>

#define MAX_SIZE 5

typedef struct{
    int top;
    int a[MAX_SIZE];
}stack;

bool isFull(stack* s){
    return (s->top < MAX_SIZE)?false:true;
}
bool isEmpty(stack* s){
    return (s->top ==0)?true:false;
}
void push(stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->a[s->top++] = value;
}
int pop(stack* s){
    if(isEmpty(s)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        s->top--;
        return s->a[s->top];
    }
}
void Print(stack* s){
    printf("Top ");
    for(int i=0;i<s->top;i++){
        printf("%d->",s->a[i]);
    }
    printf(" bottom\n");
}