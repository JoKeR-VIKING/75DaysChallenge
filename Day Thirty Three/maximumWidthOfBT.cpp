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
    int widthOfBinaryTree(TreeNode* root) 
    {
        int first = -1, last = -1, maxWidth = 1, startingPoint = 0;
        queue<pair<TreeNode*, int>> pendingNodes;
        pendingNodes.push({root, 0});
        pendingNodes.push({NULL, -1});
        
        while (true)
        {
            TreeNode* frontNode = pendingNodes.front().first;
            int index = pendingNodes.front().second;
            pendingNodes.pop();
            
            if (frontNode == NULL)
            {
                maxWidth = max(maxWidth, last - first + 1);
                
                if (pendingNodes.empty())
                    return maxWidth;
                
                pendingNodes.push({NULL, -1});
                first = last = -1;
                continue;
            }
            
            if (frontNode -> left != NULL)
            {
                if (first == -1)
                {
                    startingPoint = index;
                    first = 2 * (index - startingPoint);
                }
                else
                    last = 2 * (index - startingPoint);
                
                pendingNodes.push({frontNode -> left, 2 * (index - startingPoint)});
            }
            
            if (frontNode -> right != NULL)
            {
                if (first == -1)
                {
                    startingPoint = index;
                    first = 2 * (index - startingPoint) + 1;
                }
                else
                    last = 2 * (index - startingPoint) + 1;
                
                pendingNodes.push({frontNode -> right, 2 * (index - startingPoint) + 1});
            }
        }
        
        return maxWidth;
    }
};
