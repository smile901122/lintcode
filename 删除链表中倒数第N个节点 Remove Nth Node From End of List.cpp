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
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        
        if(head == NULL || n <= 0)    return head;
        ListNode *p1 = head;
        ListNode *p2 = head;
        while(p1->next != NULL && n > 0)
        {
            p1 = p1->next;
            --n;
        }
        if(n > 0)
        {
            head = head->next;
            delete p2;
            p2 = NULL;
            return head;
        }
        while(p1->next != NULL)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        p1 = p2->next;
        p2->next = p2->next->next;
        delete p1;
        p1 = NULL;
        return head;
    }
};
