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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        ListNode *res = new ListNode(l1->val + l2->val);
        ListNode *p = res;
        int c = p->val / 10;
        p->val %= 10;
        while(l1->next != NULL && l2->next != NULL)
        {
            int sum = l1->next->val + l2->next->val + c;
            c = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1->next != NULL)
        {
            int sum = l1->next->val + c;
            c = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1->next;
        }
        while(l2->next != NULL)
        {
            int sum = l2->next->val + c;
            c = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l2 = l2->next;
        }
        if(c)   p->next = new ListNode(c);
        return res;
    }
};
