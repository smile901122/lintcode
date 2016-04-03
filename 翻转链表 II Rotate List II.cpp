/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if(head == NULL || m >= n)    return head;
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        int count = m - 1;
        while(count > 0)   //第m-1个结点 
        {
            p = p->next;
            --count;
        }
        ListNode *left = p;
        p = p->next;
        ListNode *mNode = p;
        ListNode *pre = mNode;
        p = p->next;
        while(m < n)
        {
            ListNode *temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
            ++m;
        }
        left->next = pre;
        mNode->next = p;
        return dummy->next;
    }
};
