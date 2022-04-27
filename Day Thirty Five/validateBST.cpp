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
    bool isValidBST(TreeNode* root, pair<long long, long long> val)
    {
        if (root == NULL)
            return true;
        
        if (root -> val <= val.first || root -> val >= val.second)
            return false;
        
        bool left = isValidBST(root -> left, {val.first, root -> val});
        bool right = isValidBST(root -> right, {root -> val, val.second});
        
        return left && right;
    }
    
    bool isValidBST(TreeNode* root) 
    {
        return isValidBST(root, {LLONG_MIN, LLONG_MAX});
    }
};
