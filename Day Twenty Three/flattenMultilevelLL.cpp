/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head)
    {
        if (head == NULL)
            return NULL;
        
        Node* newHead = new Node(head -> val);
        newHead -> next = flatten(head -> child);
        
        if (newHead -> next != NULL)
            newHead -> next -> prev = newHead;
        
        Node* temp = newHead;
        while (temp -> next != NULL)
            temp = temp -> next;
        
        temp -> next = flatten(head -> next);
        
        if (temp -> next != NULL)
            temp -> next -> prev = temp;
        
        return newHead;
    }
};
