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
    bool isSymmetric(TreeNode* directionOne, TreeNode* directionTwo)
    {
        if (directionOne == NULL && directionTwo == NULL)
            return true;
        if (directionOne == NULL)
            return false;
        if (directionTwo == NULL)
            return false;
        
        if (directionOne -> val != directionTwo -> val)
            return false;
        
        bool first = isSymmetric(directionOne -> left, directionTwo -> right);
        bool second = isSymmetric(directionOne -> right, directionTwo -> left);
        
        return first && second;
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        return isSymmetric(root, root);
    }
};
