/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (root == NULL)
            return {};
        
        vector<vector<int>> traversal;
        vector<int> temp;
        
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        
        while (true)
        {
            TreeNode* frontNode = pendingNodes.front();
            pendingNodes.pop();
            
            if (frontNode == NULL)
            {
                traversal.push_back(temp);
                
                if (pendingNodes.empty())
                    return traversal;
                
                pendingNodes.push(NULL);
                temp.clear();
                continue;
            }
            
            temp.push_back(frontNode -> val);
            
            if (frontNode -> left != NULL)
                pendingNodes.push(frontNode -> left);
            
            if (frontNode -> right != NULL)
                pendingNodes.push(frontNode -> right);
        }
        
        return traversal;
    }
};
