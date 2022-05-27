class Solution {
public:
    void DFS(Node* node, unordered_map<int, Node*>& allNodes)
    {    
        Node* currNode = allNodes.count(node -> val) ? allNodes[node -> val] : new Node(node -> val);
        allNodes[node -> val] = currNode;
        
        for (int i=0;i<node -> neighbors.size();i++)
        {
            Node* tempNode = node -> neighbors[i];
            
            if (!allNodes.count(tempNode -> val))
                DFS(tempNode, allNodes);
            
            Node* childNode = allNodes.count(tempNode -> val) ? allNodes[tempNode -> val] : new Node(tempNode -> val);
            allNodes[tempNode -> val] = childNode;
            
            currNode -> neighbors.push_back(childNode);
        }
    }
    
    Node* cloneGraph(Node* node) 
    {
        if (node == NULL)
            return node;
        
        unordered_map<int, Node*> allNodes;
        DFS(node, allNodes);
        
        return allNodes[node -> val];
    }
};
