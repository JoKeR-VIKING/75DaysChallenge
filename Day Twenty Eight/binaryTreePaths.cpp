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
    void help(TreeNode* root, vector<string>& vect, string s)
    {
        if (root == NULL)
            return;

        s += to_string(root -> val);
        
        if (root -> left == NULL && root -> right == NULL)
        {
            vect.push_back(s);
            return;
        }
        
        s += "->";
        
        help(root -> left, vect, s);
        help(root -> right, vect, s);
    }
    
    vector<string> binaryTreePaths(TreeNode* root)
    {
        string s;
        vector<string> vect;
        
        help(root, vect, s);
        
        return vect;
    }
};
