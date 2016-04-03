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
class Comp{
public:
    bool operator()(ListNode *x, ListNode *y)
    {
        return x->val > y->val;
    }
};
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        priority_queue<ListNode *, vector<ListNode *>, Comp> pq;
        for(auto i : lists)
        {
            if(i != NULL)   pq.push(i);
        }
        ListNode *head, *node;
        ListNode *p, *temp;
        
        head = node = NULL;
        while (!pq.empty()) 
        {
            p = pq.top();
            temp = p->next;
            pq.pop();
            if (temp != NULL)  pq.push(temp);
            
            if (head != NULL) 
            {
                node->next = p;
                node = node->next;
            } 
            else 
            {
                head = node = p;
            }
            //node->next = NULL;
        }
        return head;
    }
};


