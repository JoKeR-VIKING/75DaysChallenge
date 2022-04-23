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
    TreeNode* helper(TreeNode* root)
    {
        if (root == NULL)
            return NULL;
        
        TreeNode* left = helper(root -> left);
        TreeNode* right = helper(root -> right);
        
        TreeNode* temp = left;
        
        while (temp != NULL && temp -> right != NULL)
            temp = temp -> right;
        
        if (temp != NULL)
            temp -> right = right;
        else
            left = right;
        
        root -> left = NULL;
        root -> right = left;
        
        return root;
    }
    
    void flatten(TreeNode* root) 
    {
        helper(root);
    }
};
