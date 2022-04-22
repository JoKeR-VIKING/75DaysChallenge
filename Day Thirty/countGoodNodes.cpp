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
    int goodNodes(TreeNode* root, int prev)
    {
        if (root == NULL)
            return 0;
        
        prev = max(prev, root -> val);
        
        int x = goodNodes(root -> left, prev);
        int y = goodNodes(root -> right, prev);
        
        if (root -> val < prev)
            return x + y;
        
        return x + y + 1;
    }
    
    int goodNodes(TreeNode* root)
    {
        return goodNodes(root, INT_MIN);
    }
};
