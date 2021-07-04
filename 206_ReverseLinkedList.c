/*
* @Author: zero
* @Date:   2021-06-30 20:28:29
* @Last Modified time: 2021-06-30 20:41:25
* @Description: Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverse(struct ListNode* cur, struct ListNode* pre){
    if (!cur)
        return pre;
    struct ListNode* temp;
    temp = cur;
    cur = cur->next;
    temp->next = pre;
    return reverse(cur, temp);
}

struct ListNode* reverseList(struct ListNode* head) {
    return reverse(head, NULL);
}