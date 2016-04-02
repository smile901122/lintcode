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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        if(head == NULL || head->next == NULL)    return head;
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        while(p1 != NULL && p2 != NULL)
        {
            int temp = p1->val;
            p1->val = p2->val;
            p2->val = temp;
            if(p1->next->next != NULL && p2->next->next != NULL)
            {
                p1 = p1->next->next;
                p2 = p2->next->next;
            }
            else break;
        }
        return head;
    }
};
