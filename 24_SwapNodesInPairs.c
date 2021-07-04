/*
* @Author: zero
* @Date:   2021-07-01 22:54:35
* @Last Modified time: 2021-07-02 08:21:07
* @Description: Given a linked list, swap every two adjacent nodes and return its head.
* You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
*/
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

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

struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next)
        return head;
    struct ListNode *cur = (struct ListNode*)malloc(sizeof(struct ListNode));
    cur->next = head;
    head = head->next;
    struct ListNode *temp1;
    struct ListNode *temp2;
    while (cur->next && cur->next->next) {
        temp1 = cur->next;
        cur->next = cur->next->next;
        temp2 = cur->next->next;
        cur->next->next = temp1;
        temp1->next = temp2;
        cur = temp1;  // 不能是 cur->next = temp2
    }
    return head;
}

int main() {
    int a[] = {6, 5, 4, 3, 2, 1};
    struct ListNode *head = NULL;
    createList(head, a, 6);
    printList(head);
    printList(swapPairs(head));
    return 0;
}
