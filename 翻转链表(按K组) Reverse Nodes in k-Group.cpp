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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2 || head == NULL)  return head;
        
        ListNode *newHead = NULL;
        ListNode *newTail = NULL;
        ListNode *h;
        
        ListNode *nh;
        ListNode *nt;
        
        while (head != NULL) {
            //判断剩余的链表是否不够k个
            ListNode *p = head;
            int i = k - 1;
            while(p != NULL && i--)     p = p->next;
            if (i >= 0) {//若不够
                if (newHead == NULL)    newHead = head;
                else    newTail->next = head;   //将剩余的链表接在尾部
                break;
            }
            //若够k个，将子链拆出来
            h = head;
            head = p->next; //下一个要翻转的子链的头
            p->next = NULL; //将子链尾置为NULL
            
            reverseList(h, nh, nt);
            //连接子链
            if (newHead == NULL) {
                newHead = nh;
                newTail = nt;
            }  
            else {
                newTail->next = nh;
                newTail = nt;
            }
        }
        return newHead;
    }
    
protected:
    void reverseList(ListNode* head, ListNode* &newHead, ListNode* &newTail) {
        if (head == NULL || head->next == NULL) {
            newHead = newTail = head;
            return;
        }
        
        newTail = head;
        newHead = NULL;
        ListNode *next;
        while(head != NULL){
            next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
    }
};
