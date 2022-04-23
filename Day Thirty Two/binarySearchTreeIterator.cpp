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
class BSTIterator 
{
private:
    vector<int> inorder;
    int index = 0;
public:
    void traversal(TreeNode* root)
    {
        if (root == NULL)
            return;
        
        traversal(root -> left);
        inorder.push_back(root -> val);
        traversal(root -> right);
    }
    
    BSTIterator(TreeNode* root) 
    {
        traversal(root);
    }
    
    int next() 
    {
        return inorder[index++];
    }
    
    bool hasNext() 
    {
        return index != inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
