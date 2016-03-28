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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        if(head == NULL)    return head;
        
        ListNode *dummy = new ListNode(0);
        ListNode *cur = head;
        while(cur != NULL)
        {
            ListNode *pre = dummy;
            while(pre->next != NULL && pre->next->val < cur->val)
            {
                pre = pre->next;
            }
            ListNode *temp = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = temp;
        }
        return dummy->next;
        
        //method 2:
        /*
		ListNode *h = NULL;
		ListNode *p;
		ListNode *q;
		
		h = head;
		head = head->next;
		h->next = NULL;
		while (head != NULL) {
			p = head;
			head = head->next;
			if (p->val <= h->val) {
				p->next = h;
				h = p;
				continue;
			}
			q = h;
			while (q->next != NULL && q->next->val < p->val) {
				q = q->next;
			}
			p->next = q->next;
			q->next = p;
		}
		return h;
        */
    }
};
