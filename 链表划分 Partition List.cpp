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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        ListNode *small = new ListNode(0);
        ListNode *big = new ListNode(0);
        ListNode *s = small;
        ListNode *b = big;
        ListNode *p = head;
        while(p != NULL)
        {
            if(p->val < x)
            {
                s->next = p;
                s = s->next;
            }
            else
            {
                b->next = p;
                b = b->next;
            }
            p = p->next;
        }
        b->next = NULL;
        s->next = big->next;
        return small->next;
    }
};


