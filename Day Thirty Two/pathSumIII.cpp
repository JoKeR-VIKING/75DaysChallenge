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
    void backTrack(TreeNode* root, long long targetSum, int& res)
    {
        if (root == NULL)
            return;
        if (root -> val == targetSum)
            res++;
        
        backTrack(root -> left, targetSum - root -> val, res);        
        backTrack(root -> right, targetSum - root -> val, res);
    }
    
    void getPathSum(TreeNode* root, long long targetSum, int& res)
    {
        if (root == NULL)
            return;
        
        backTrack(root, targetSum, res);
        getPathSum(root -> left, targetSum, res);        
        getPathSum(root -> right, targetSum, res);
    }
    
    int pathSum(TreeNode* root, int targetSum) 
    {
        int res = 0;
        getPathSum(root, targetSum, res);
        
        return res;
    }
};
