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
        
        vector<TreeNode*> currAns;
        
        for (int i=start;i<=end;i++)
        {
            vector<TreeNode*> left = generateTrees(start, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, end);
            
            for (auto& l : left)
            {
                for (auto& r : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root -> left = l;
                    root -> right = r;
                    
                    currAns.push_back(root);
                }
            }
        }
        
        return currAns;
    }
    
    vector<TreeNode*> generateTrees(int n) 
    {
        return generateTrees(1, n);
    }
};
