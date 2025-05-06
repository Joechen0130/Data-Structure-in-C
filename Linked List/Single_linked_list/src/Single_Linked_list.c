// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include "Single_Linked_list.h"

node* createNode(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insertBeginning(node** head, int data){
    node* temp = createNode(data);
    temp->next = *head;
    *head = temp;
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
    current->next = temp;
}
void printLinkedList(node** head){
    node* current = *head;
    while(current){
        printf("%d->",current->data);
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
    if(*head==NULL || (*head)->next ==NULL) return;
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
void deleteBeginning(node** head){
    if(*head==NULL) return;
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