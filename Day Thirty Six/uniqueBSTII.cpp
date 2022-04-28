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
    vector<TreeNode*> generateTrees(int start, int end)
    {
        if (start > end)
            return {NULL};
        
        vector<TreeNode*> ans;
        
        for (int i=start;i<=end;i++)
        {
            vector<TreeNode*> left = generateTrees(start, i-1);
            vector<TreeNode*> right = generateTrees(i+1, end);
            
            for (auto lr : left)
            {
                for (auto rr : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root -> left = lr;
                    root -> right = rr;
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) 
    {
        return generateTrees(1, n);
    }
};
