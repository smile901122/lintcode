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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        ListNode *head;
        ListNode *p;
        if(l1->val < l2->val)   
        {
            head = l1;
            l1 = l1->next;
        }
        else 
        {
            head = l2;
            l2 = l2->next;
        }
        p = head;
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if(l1 != NULL)  p->next = l1;
        else    p->next = l2;
        return head;
    }
};
