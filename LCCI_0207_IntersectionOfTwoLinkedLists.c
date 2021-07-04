/*
* @Author: zero
* @Date:   2021-07-02 09:46:24
* @Last Modified time: 2021-07-04 16:42:57
* @Description: Given two (singly) linked lists, determine if the two lists intersect.
*  Return the inter secting node. Note that the intersection is defined based on reference, not value.
*  That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (!headA || !headB)
        return NULL;
    int lenA = 0, lenB = 0;
    struct ListNode *A = headA, *B = headB;
    while (A) {
        lenA ++;
        A = A->next;
    }
    while (B) {
        lenB ++;
        B = B->next;
    }
    A = headA, B = headB;
    if (lenA - lenB > 0) {
        for (int i = lenA - lenB; i > 0 ;i --)
            A = A->next;
    } else {
        for (int i = lenB - lenA; i > 0 ;i --)
            B = B->next;
    }
    while (A) {
        if (A == B)
            return A;
        A = A->next;
        B = B->next;
    }
    return NULL;
}

/**
 * A 长度为 a, B 长度为 b，假设存在交叉点，此时 A 到交叉点距离为 c，而 B 到交叉点距离为 d
 * 后续交叉后长度是一样的，那么就是 a-c = b-d -> a+d = b+c
 * 这里意味着只要分别让 A 和 B 额外多走一遍 B 和 A，那么必然会走到交叉
 * 注意这里边缘情况是，大家都走到 null 依然没交叉，那么正好返回 null即可
 */
struct ListNode *getIntersectionNode2(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode *a = headA;
    struct ListNode *b = headB;
    while (a != b) {
        a = a != NULL ? a->next : headB;
        b = b != NULL ? b->next : headA;
    }
    return a;
}
