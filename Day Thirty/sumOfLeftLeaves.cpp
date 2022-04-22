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
    int sumOfLeftLeaves(TreeNode* root, bool direction)
    {
        if (root == NULL)
            return 0;
        if (root -> left == NULL && root -> right == NULL)
            return direction ? root -> val : 0;
        
        int x = sumOfLeftLeaves(root -> left, true);
        int y = sumOfLeftLeaves(root -> right, false);
        
        return x + y;
    }
    
    int sumOfLeftLeaves(TreeNode* root) 
    {
        return sumOfLeftLeaves(root, false);
    }
};
