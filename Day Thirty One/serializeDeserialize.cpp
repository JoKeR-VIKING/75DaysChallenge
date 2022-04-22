/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string serialized;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        
        while (!pendingNodes.empty())
        {
            int size = pendingNodes.size();
            
            while (size-- > 0)
            {
                TreeNode* frontNode = pendingNodes.front();
                pendingNodes.pop();
                
                if (frontNode == NULL)
                {
                    serialized += "#,";
                    continue;
                }
                else
                    serialized += to_string(frontNode -> val) + ',';
                
                pendingNodes.push(frontNode -> left);
                pendingNodes.push(frontNode -> right);
            }
            
            serialized.pop_back();
            serialized += ';';
        }
        
        serialized.pop_back();
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        vector<vector<string>> levelOrderTree;
        stringstream ss1(data);
        string word;

        while (getline(ss1, word, ';'))
        {
            stringstream ss2(word);
            string ch;
            levelOrderTree.push_back({});

            while (getline(ss2, ch, ','))
                levelOrderTree.back().push_back(ch);
        }

        int index1 = 0;
        TreeNode* root = NULL;
        queue<TreeNode**> pendingNodes;
        pendingNodes.push(&root);

        while (index1 < levelOrderTree.size() && !pendingNodes.empty())
        {
            int size = pendingNodes.size(), index2 = 0;

            while (size-- > 0)
            {
                TreeNode** frontNode = pendingNodes.front();
                pendingNodes.pop();

                try
                {
                    *frontNode = new TreeNode(stoi(levelOrderTree[index1][index2++]));
                }
                catch (exception e)
                {
                    *frontNode = NULL;
                    continue;
                }

                pendingNodes.push(&(*frontNode) -> left);
                pendingNodes.push(&(*frontNode) -> right);
            }

            index1++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
