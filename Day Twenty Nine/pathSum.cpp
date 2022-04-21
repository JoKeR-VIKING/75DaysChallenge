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
    bool hasPathSum(TreeNode* root, int sum, int targetSum)
    {
        if (root == NULL)
            return false;
        if (root -> left == NULL && root -> right == NULL)
        {
            if (sum + root -> val == targetSum)
                return true;
            
            return false;
        }
        
        bool left = hasPathSum(root -> left, sum + root -> val, targetSum);
        bool right = hasPathSum(root -> right, sum + root -> val, targetSum);
        
        return left || right;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return hasPathSum(root, 0, targetSum);
    }
};
