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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(head == NULL)    return head;
        ListNode *p = head;
        while(p->next != NULL)
        {
            if(p->next->val == p->val)
            {
                ListNode *temp = p->next;
                p->next = p->next->next;
                temp = NULL;
                delete temp;
            }
            else
            {
                p = p->next;
            }
        }
        return head;
    }
};
