/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        queue<TreeNode*> pendingNodes;
        unordered_map<TreeNode*, TreeNode*> parent;
        
        pendingNodes.push(root);
        
        while (!pendingNodes.empty())
        {
            TreeNode* frontNode = pendingNodes.front();
            pendingNodes.pop();
            
            if (frontNode -> left != NULL)
            {
                parent[frontNode -> left] = frontNode;
                pendingNodes.push(frontNode -> left);
            }
            
            if (frontNode -> right != NULL)
            {
                parent[frontNode -> right] = frontNode;
                pendingNodes.push(frontNode -> right);
            }
        }
        
        unordered_map<TreeNode*, bool> visited;
        pendingNodes.push(target);
        pendingNodes.push(NULL);
        int distance = 0;
        
        while (distance < k && !pendingNodes.empty())
        {
            TreeNode* frontNode = pendingNodes.front();
            pendingNodes.pop();
            
            if (frontNode == NULL)
            {
                distance++;
                pendingNodes.push(NULL);
                continue;
            }
            
            visited[frontNode] = true;
            
            if (frontNode -> left != NULL && !visited[frontNode -> left])
            {
                visited[frontNode -> left] = true;
                pendingNodes.push(frontNode -> left);
            }
            
            if (frontNode -> right != NULL && !visited[frontNode -> right])
            {
                visited[frontNode -> right] = true;
                pendingNodes.push(frontNode -> right);
            }
            
            if (parent[frontNode] != NULL && !visited[parent[frontNode]])
            {
                visited[parent[frontNode]];
                pendingNodes.push(parent[frontNode]);
            }
        }
        
        vector<int> ans;
        
        while (pendingNodes.size() > 1)
        {
            TreeNode* frontNode = pendingNodes.front();
            pendingNodes.pop();
            
            ans.push_back(frontNode -> val);
        }
        
        return ans;
    }
};
