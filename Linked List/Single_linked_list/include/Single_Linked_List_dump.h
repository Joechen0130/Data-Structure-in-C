#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

#include "Single_Linked_list.h"

node* myLinkedListCreate();
int myLinkedListGet(node* obj, int index);
void myLinkedListAddAtHead(node* obj, int val);
void myLinkedListAddAtTail(node* obj, int val);
void myLinkedListAddAtIndex(node* obj, int index, int val);
void myLinkedListDeleteAtIndex(node* obj, int index);
void myLinkedListFree(node* obj);
void Print(node* obj);  // optional for debug

#endif
