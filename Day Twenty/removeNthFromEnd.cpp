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
    ListNode* helpRemove(ListNode* head, int& n)
    {
        if (head == NULL)
            return NULL;
        
        ListNode* temp = helpRemove(head -> next, n);
        
        if (n == 1)
        {
            n--;
            return head -> next;
        }
        else
        {
            n--;
            head -> next = temp;
            return head;
        }
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        return helpRemove(head, n);
    }
};
