/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void helpAdd(ListNode* l, stack<int>& stk)
    {
        if (l == NULL)
            return;
        
        stk.push(l -> val);
        helpAdd(l -> next, stk);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<int> stk1, stk2, stk3;
        int carry = 0;
        ListNode* head;
        
        helpAdd(l1, stk1);
        helpAdd(l2, stk2);
        
        while (!stk1.empty() && !stk2.empty())
        {
            if (stk1.top() + stk2.top() + carry > 9)
            {
                stk3.push((stk1.top() + stk2.top() + carry) % 10);
                carry = 1;
            }
            else
            {
                stk3.push(stk1.top() + stk2.top() + carry);
                carry = 0;
            }
            
            stk1.pop();
            stk2.pop();
        }
        
        while (!stk1.empty())
        {
            if (stk1.top() + carry > 9)
            {
                stk3.push((stk1.top() + carry) % 10);
                carry = 1;
            }
            else
            {
                stk3.push(stk1.top() + carry);
                carry = 0;
            }
            
            stk1.pop();
        }
        
        while (!stk2.empty())
        {
            if (stk2.top() + carry > 9)
            {
                stk3.push((stk2.top() + carry) % 10);
                carry = 1;
            }
            else
            {
                stk3.push(stk2.top() + carry);
                carry = 0;
            }
            
            stk2.pop();
        }
        
        ListNode* temp;
        
        if (carry == 1)
        {
            head = new ListNode(1);
            temp = head;
        }
        else
        {
            head = new ListNode(stk3.top());
            stk3.pop();
            temp = head;
        }
        
        while (!stk3.empty())
        {
            temp -> next = new ListNode(stk3.top());
            stk3.pop();
            temp = temp -> next;
        }
        
        return head;
    }
};
