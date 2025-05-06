#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

// 定義雙向鏈表的節點結構
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} node;

// 創建新節點
node* createNode(int data);

// 在鏈表頭部插入節點
void insertBeginning(node** head, int data);

// 在鏈表尾部插入節點
void insertEnd(node** head, int data);

// 打印鏈表
void printLinkedList(node** head);

// 獲取鏈表的中間節點
void getMiddleNode(node** head);

// 反轉鏈表
void reverseLinkedList(node** head);

// 刪除頭部節點
void deleteBeginning(node** head);

// 刪除尾部節點
void deleteEnd(node** head);

#endif // SINGLE_LINKED_LIST_H
