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
    void findIntersect(ListNode* head, stack<ListNode*>& stk)
    {
        if (head == NULL)
            return;
        
        stk.push(head);
        
        findIntersect(head -> next, stk);
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        stack<ListNode*> stk1, stk2;
        ListNode* prev = NULL;
        
        findIntersect(headA, stk1);
        findIntersect(headB, stk2);
        
        prev = NULL;
        
        while (!stk1.empty() && !stk2.empty())
        {
            if (stk1.top() != stk2.top())
                return prev;
            
            prev = stk1.top();
            stk1.pop();
            stk2.pop();
        }
        
        return prev;
    }
};
