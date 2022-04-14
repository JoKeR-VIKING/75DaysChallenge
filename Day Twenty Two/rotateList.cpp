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
    
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head == NULL || k == 0)
            return head;
        
        k = k % getLength(head);
        
        if (k == 0)
            return head;
        
        ListNode* first = head;
        ListNode* second = head;
        
        for (int i=0;i<k;i++)
            first = first -> next;
        
        while (first -> next != NULL)
        {
            second = second -> next;
            first = first -> next;
        }
        
        first -> next = head;
        ListNode* newHead = second -> next;
        second -> next = NULL;
        return newHead;
    }
};
