/*
* @Author: zero
* @Date:   2021-07-02 09:46:24
* @Last Modified time: 2021-07-02 10:04:23
* @Description: Given two (singly) linked lists, determine if the two lists intersect.
*  Return the inter secting node. Note that the intersection is defined based on reference, not value.
*  That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.
*/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
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
