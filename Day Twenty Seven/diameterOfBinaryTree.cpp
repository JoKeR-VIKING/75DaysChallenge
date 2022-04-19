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
    int diameterOfBinaryTree(TreeNode* root, int& maxHeight)
    {
        if (root == NULL)
            return 0;
        
        int left = diameterOfBinaryTree(root -> left, maxHeight);
        int right = diameterOfBinaryTree(root -> right, maxHeight);
        
        maxHeight = max(left + right + 1, maxHeight);
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int maxHeight = 0;
        diameterOfBinaryTree(root, maxHeight);
        return maxHeight - 1;
    }
};
