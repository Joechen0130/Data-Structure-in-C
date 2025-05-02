// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

/*
* MyLinkedList* obj = myLinkedListCreate();
* int param_1 = myLinkedListGet(obj, index);
* myLinkedListAddAtHead(obj, val);
* myLinkedListAddAtTail(obj, val);
* myLinkedListAddAtIndex(obj, index, val);
* myLinkedListDeleteAtIndex(obj, index);
* myLinkedListFree(obj);
*/

typedef struct node{
    int data;
    struct node* next;
}node;

void Print(node* obj) {
    node* current = obj->next; // 跳過 dummy head
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
node* myLinkedListCreate(){
    node* dump = (node*)malloc(sizeof(node));
    dump->data = 0;
    dump->next = NULL;
    return dump;
}

int myLinkedListGet(node* obj, int index){
    node* temp = obj->next;
    while(temp && index>0){
        temp = temp->next;
        index--;
    }
    return (temp && index==0)?temp->data:-1;
}
void myLinkedListAddAtHead(node* obj,int val){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = obj->next;
    obj->next = temp;
}
void myLinkedListAddAtTail(node* obj,int val){
    node* current = obj->next;
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    
    while(current->next){
        current=current->next;
    }
    current->next = temp;
}
void myLinkedListAddAtIndex(node* obj,int index, int val){
    node* current = obj;
    while(current && index>0){
        current = current->next;
        index--;
    }
    if(current==NULL) return;
    
    node* temp = (node*)malloc(sizeof(node));
    temp->data = val;
    
    temp->next = current->next;
    current->next =temp;
    
}
void myLinkedListDeleteAtIndex(node* obj,int index){
    node* current = obj;
    while(current->next && index>0){
        current = current->next;
        index--;
    }
    if(current->next==NULL) return;
    current->next = current->next->next;
}
void myLinkedListFree(node* obj){
    node* current = obj;
    while(current){
        node* temp = current;
        current=current->next;
        free(temp);
    }
}

int main() {
    node* list = myLinkedListCreate();

    myLinkedListAddAtHead(list, 10);//10->NULL
    Print(list);
    myLinkedListAddAtTail(list, 20);//10->20->NULL
    Print(list);
    myLinkedListAddAtIndex(list, 1, 15);//10->15->20->NULL
    Print(list);
    printf("Index 1: %d\n", myLinkedListGet(list, 1));

    myLinkedListDeleteAtIndex(list, 1);  //刪除 15
    Print(list); 
    myLinkedListDeleteAtIndex(list, 0);  //刪除 15
    Print(list); 
    myLinkedListDeleteAtIndex(list, 0);  //刪除 15
    Print(list); 
    myLinkedListDeleteAtIndex(list, 0);  //刪除 15
    Print(list);
    myLinkedListFree(list);
    return 0;
}