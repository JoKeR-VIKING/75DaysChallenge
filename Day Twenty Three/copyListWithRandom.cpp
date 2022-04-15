/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* fillMap(Node* head, unordered_map<int, Node*>& indexMap, unordered_map<Node*, int>& nodeMap, int index)
    {
        if (head == NULL)
            return NULL;
        
        Node* newHead = new Node(head -> val);
        indexMap[index] = newHead;
        nodeMap[head] = index;
        
        newHead -> next = fillMap(head -> next, indexMap, nodeMap, index + 1);
        return newHead;
    }
    
    void fillRandom(Node* head, Node* newHead, unordered_map<int, Node*>& indexMap, unordered_map<Node*, int>& nodeMap)
    {
        if (head == NULL)
            return;
        
        if (head -> random != NULL)
            newHead -> random = indexMap[nodeMap[head -> random]];
        else
            newHead -> random = NULL;
        
        fillRandom(head -> next, newHead -> next, indexMap, nodeMap);
    }
    
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, int> nodeMap;
        unordered_map<int, Node*> indexMap;
        
        Node* newHead = fillMap(head, indexMap, nodeMap, 0);
        
        fillRandom(head, newHead, indexMap, nodeMap);
        
        return newHead;
    }
};
