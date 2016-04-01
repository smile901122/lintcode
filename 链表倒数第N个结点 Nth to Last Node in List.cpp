/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        if(head == NULL)    return head;
        ListNode *p1 = head;
        ListNode *p2 = head;
        while(p1->next != NULL && n > 1)
        {
            p1 = p1->next;
            --n;
        }
        while(p1->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
        /*
        ListNode *p1, *p2;
        p1 = head;
        while(n > 0)
        {
            p1 = p1->next;
            --n;
        }
        p2 = head;
        while (p1 != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
        */
    }
};


