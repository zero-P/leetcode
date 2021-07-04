/*
* @Author: zero
* @Date:   2021-07-02 08:59:13
* @Last Modified time: 2021-07-02 09:12:09
* @Description: Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *h = (struct ListNode*)malloc(sizeof(struct ListNode));
    h->next = head;
    struct ListNode *p = h;
    for (int i = 1; i < n; i++)
        head = head->next;
    while (head->next) {
        p = p->next;
        head = head->next;
    }
    head = p->next;
    p->next = p->next->next;  
    free(head);
    return h->next;
}

void printList(struct ListNode* head) {
    struct ListNode *t = head;
    while (t) {
        printf("%d ", t->val);
        t = t->next;
    }
    printf("\n");
}

void createList(struct ListNode* &head, int a[], int n) {
    for (int i = 0; i < n; i++) {
        struct ListNode *s = (struct ListNode*)malloc(sizeof(struct ListNode));
        s->val = a[i];
        s->next = head;
        head = s;
    }
}

int main() {
    int a[] = {1};
    struct ListNode *head = NULL;
    createList(head, a, 1);
    printList(head);
    printList(removeNthFromEnd(head, 1));
    return 0;
}
