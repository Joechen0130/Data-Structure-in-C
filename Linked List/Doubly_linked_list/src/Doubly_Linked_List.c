// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include "Doubly_Linked_List.h"

node* createNode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void insertBeginning(node** head, int data){
    node* temp = createNode(data);
   if(*head==NULL) *head= temp;
   else{
       (*head)->prev = temp;
       temp->next = *head;
       *head = temp;
   }
}
void insertEnd(node** head, int data){
    node* temp = createNode(data);
    if(*head==NULL){
        *head=temp;
        return;
    }
    node* current = *head;
    while(current->next){
        current = current->next;
    }
    temp->prev = current;
    current->next = temp;
}
void printLinkedList(node** head){
    node* current = *head;
    while(current){
        printf("%d<->",current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void getMiddleNode(node** head){
    node* fast = *head;
    node* slow = *head;
    while(fast&&fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("Middle node is %d\n",slow->data);
}
void reverseLinkedList(node** head){
    if(*head==NULL || (*head)->next==NULL) return;
    node* current = *head;
    node* temp = NULL;
    while(current!=NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
   *head = temp->prev;
}
void deleteBeginning(node** head){
    if(*head==NULL){
        return;
    }
    (*head)->prev =NULL;
    *head = (*head)->next;
}
void deleteEnd(node** head){
    if(*head==NULL||(*head)->next==NULL){
        *head = NULL;
        return;
    }
    node* current = *head;
    while(current&& current->next&&current->next->next){
        current = current->next;
    }
    current->next = NULL;
}