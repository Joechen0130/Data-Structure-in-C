#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    int data;
    struct node* next;
} node;

// 基本操作函式
node* createNode(int data);
void insertBeginning(node** head, int data);
void insertEnd(node** head, int data);
void printLinkedList(node** head);
void getMiddleNode(node** head);
void reverseLinkedList(node** head);
void deleteBeginning(node** head);
void deleteEnd(node** head);

#endif
