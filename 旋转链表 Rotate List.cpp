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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(k == 0 || head == NULL)  return head;
        
        ListNode *p = head;
        
        int n = 1;
        while(p->next != NULL)
        {
            p = p->next;
            ++n;
        }
        p->next = head;
        p = head;
        k = n - k % n;
        for(int i = 0; i < k - 1 ; ++i)
        {
            p = p->next;
        }
        ListNode *tail = p;
        p = p->next;
        tail->next = NULL;
        
        return p;
    }
};
