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
    int getLength(ListNode* head)
    {
        if (head == NULL)
            return 0;
        
        return 1 + getLength(head -> next);
    }
    
    void addition(ListNode* l1, ListNode* l2, int& carry)
    {
        if (l1 == NULL)
            return;
        
        addition(l1 -> next, l2 -> next, carry);
        int sum = l1 -> val + l2 -> val + carry;
        
        l1 -> val = sum % 10;
        carry = sum / 10;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int size1 = getLength(l1);
        int size2 = getLength(l2);
        
        while (size1 > size2)
        {
            ListNode* newNode = new ListNode(0);
            newNode -> next = l2;
            l2 = newNode;
            size2++;
        }
        
        while (size2 > size1)
        {
            ListNode* newNode = new ListNode(0);
            newNode -> next = l1;
            l1 = newNode;
            size1++;
        }
        
        int carry = 0;
        addition(l1, l2, carry);
        
        if (carry > 0)
        {
            ListNode* newNode = new ListNode(carry);
            newNode -> next = l1;
            l1 = newNode;
        }
        
        return l1;
    }
};
