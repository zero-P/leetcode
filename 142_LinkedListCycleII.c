/*
* @Author: zero
* @Date:   2021-07-04 09:27:01
* @Last Modified time: 2021-07-04 09:57:40
* @Description: Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
*/

struct ListNode *detectCycle(struct ListNode *head) {
    if (!head || !head->next)
        return NULL;
    struct ListNode *fast, *slow;
    fast = slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow != fast)
        return NULL;
    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}