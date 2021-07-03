/*
* @Author: zero
* @Date:   2021-07-03 15:20:41
* @Last Modified time: 2021-07-03 15:21:49
* @Description: Given head, the head of a linked list, determine if the linked list has a cycle in it.
* Return true if there is a cycle in the linked list. Otherwise, return false.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (!head || !head->next)
        return false;
    struct ListNode *fast, *slow;
    fast = slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}
