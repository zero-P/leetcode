/*
* @Author: zero
* @Date:   2021-06-30 14:51:48
* @Last Modified time: 2021-07-04 16:43:50
* @Description: Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
* Assume all nodes in the linked list are 0-indexed.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int length;
} MyLinkedList;

/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *linkedList = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->length = 0;
    return linkedList;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->length)
        return -1;
    Node *p = obj->head;
    while (index--)
        p = p->next;
    return p->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *s = (Node*)malloc(sizeof(Node));
    s->val = val;
    s->next = obj->head;
    obj->head = s;
    if (!obj->length)
        obj->tail = s;
    obj->length++;
    return;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *s = (Node*)malloc(sizeof(Node));
    s->val = val;
    s->next = NULL;
    if (!obj->length) {
        obj->tail = s;
        obj->head = s;
        obj->length++;
    } else {
        obj->tail->next = s;
        obj->tail = s;
        obj->length++;
    }
    return;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index > obj->length)
        return;
    if (index <= 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }
    if (index == obj->length) {
        myLinkedListAddAtTail(obj, val);
        return;
    }
    Node *s = (Node*)malloc(sizeof(Node));
    s->val = val;
    s->next = NULL;
    Node *p = obj->head;
    index--;
    while (index--)
        p = p->next;
    s->next = p->next;
    p->next = s;
    obj->length++;
    return;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->length)
        return;
    Node *p = (Node*)malloc(sizeof(Node));
    p->next = obj->head;
    Node *h = p;
    while (index--)
        p = p->next;
    Node *q = p->next;
    p->next = p->next->next;
    free(q);
    obj->length--;
    obj->head = h->next;
    if (obj->length == 0 || obj->length == 1)
        obj->tail = obj->head;
    if (p->next == NULL)  // 删的是尾结点
        obj->tail = p;
    return;
}

void myLinkedListFree(MyLinkedList* obj) {
    if (!obj->length == 0) {
        free(obj);
        return;
    }
    if (obj->length == 1) {
        free(obj->head);
        free(obj);
        return;
    }
    Node *p = obj->head;
    Node *q;
    while (p){
        q = p->next;
        free(p);
        p = q;
    }
    free(obj);
    return;
}

void printMyLinkedList(MyLinkedList* obj) {
    Node *p = obj->head;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
    return;
}

int main() {
    // ["MyLinkedList","addAtHead","addAtIndex","addAtTail","addAtHead","addAtIndex","addAtTail","addAtTail","addAtIndex","deleteAtIndex","deleteAtIndex","addAtTail"]
    // [[],[0],[1,4],[8],[5],[4,3],[0],[5],[6,3],[7],[5],[4]]
    MyLinkedList *L = myLinkedListCreate();
    myLinkedListAddAtHead(L, 0);
    printMyLinkedList(L);
    myLinkedListAddAtIndex(L, 1, 4);
    printMyLinkedList(L);
    myLinkedListAddAtTail(L, 8);
    printMyLinkedList(L);
    myLinkedListAddAtHead(L, 5);
    printMyLinkedList(L);
    myLinkedListAddAtIndex(L, 4, 3);
    printMyLinkedList(L);
    myLinkedListAddAtTail(L, 0);
    printMyLinkedList(L);
    myLinkedListAddAtTail(L, 5);
    printMyLinkedList(L);
    myLinkedListAddAtIndex(L, 6, 3);
    printMyLinkedList(L);
    myLinkedListDeleteAtIndex(L, 7);
    printf("*%d\n", L->length);
    printMyLinkedList(L);
    myLinkedListDeleteAtIndex(L, 5);
    printf("*%d\n", L->length);
    printMyLinkedList(L);
    myLinkedListAddAtTail(L, 4);
    printf("*%d\n", L->length);
    printMyLinkedList(L);
    return 0;
}
