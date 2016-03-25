/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        ListNode *p = head;
        
        while(p != NULL && p->val == val)   //if head->val == val  delete head
        {
            head = head->next;
            delete p;
            p = head;
        }
        if(p == NULL)   return head;
        while(p->next != NULL)  
        {
            if(p->next->val == val) // if p->next-val == val,delete p->next;
            {
                ListNode *temp = p->next;
                p->next = temp->next;
                delete temp;
                temp = NULL;
            }
            else    //p = p->next;
            {
                p = p->next;
            }
        }
        return head;
    }
};
