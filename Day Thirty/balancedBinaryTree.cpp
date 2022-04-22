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
    int checkBalance(TreeNode* root, bool& check)
    {
        if (root == NULL)
            return 0;
        
        int leftHeight = checkBalance(root -> left, check);
        int rightHeight = checkBalance(root -> right, check);
        
        if (abs(leftHeight - rightHeight) > 1)
            check = false;
        
        return max(leftHeight, rightHeight) + 1;
    }
    
    bool isBalanced(TreeNode* root)
    {
        bool check = true;
        checkBalance(root, check);
        return check;
    }
};
