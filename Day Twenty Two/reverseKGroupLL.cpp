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
    ListNode* reverseKGroup(ListNode* head, int k, int len)
    {
        if (head == NULL || k > len)
            return head;
        
        ListNode* curr = head, *prev = NULL, *next = NULL;
        int tempK = k;
        
        while (tempK--)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        head -> next = reverseKGroup(curr, k, len - k);
        return prev;
    }
    
    int length(ListNode* head)
    {
        if (head == NULL)
            return 0;
        
        return 1 + length(head -> next);
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        int len = length(head);
        return reverseKGroup(head, k, len);
    }
};
