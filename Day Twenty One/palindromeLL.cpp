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
class Solution 
{
public:
    bool isPalindrome(ListNode*& head1, ListNode* head2)
    {
        if (head2 == NULL)
            return true;
        
        bool check = isPalindrome(head1, head2 -> next);
        
        if (head2 -> val != head1 -> val)
        {
            head1 = head1 -> next;
            return false;
        }
        
        head1 = head1 -> next;
        return check;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode* temp = head;
        return isPalindrome(temp, head);
    }
};
