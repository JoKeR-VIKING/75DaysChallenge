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
    vector<int> rightSideView(TreeNode* root)
    {
        int flag = 1;
        vector<int> vect;
        
        if (root == NULL)
            return vect;
        
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        
        while (!pendingNodes.empty())
        {
            TreeNode* frontNode = pendingNodes.front();
            pendingNodes.pop();
            
            if (frontNode == NULL)
            {
                if (pendingNodes.empty())
                    return vect;
                
                pendingNodes.push(NULL);
                flag = 1;
            }
            else
            {
                if (flag == 1)
                {
                    vect.push_back(frontNode -> val);
                    flag = 0;
                }
                
                if (frontNode -> right != NULL)
                    pendingNodes.push(frontNode -> right);
                if (frontNode -> left != NULL)
                    pendingNodes.push(frontNode -> left);
            }
        }
        
        return vect;
    }
};
