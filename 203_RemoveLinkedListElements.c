/*
* @Author: zero
* @Date:   2021-06-30 12:23:02
* @Last Modified time: 2021-06-30 12:42:26
* @Description: Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->next = head;
    struct ListNode *h = p;
    while (p->next) {
    	if (p->next->val == val)
   			p->next = p->next->next;
   		else
   			p = p->next;
    }
    return h->next;
}
