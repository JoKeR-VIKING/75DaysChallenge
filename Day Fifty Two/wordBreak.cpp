class TrieNode
{
public:
    bool isTerminal;
    vector<TrieNode*> children;
    
    TrieNode()
    {
        children = vector<TrieNode*>(26);
        isTerminal = false;
    }
};

class Solution 
{
public:
    void insertWord(string word, TrieNode* root)
    {
        if (word == "")
        {
            root -> isTerminal = true;
            return;
        }
        
        if (root -> children[word[0] - 'a'] == NULL)
            root -> children[word[0] - 'a'] = new TrieNode();
        
        insertWord(word.substr(1), root -> children[word[0] - 'a']);
    }
    
    bool findWord(string s, TrieNode* root, queue<int>& startIndices, int index, unordered_map<int, bool>& visited)
    {
        if (s == "")
            return root -> isTerminal;
        if (root -> isTerminal)
        {
            if (!visited.count(index))
            {
                visited[index] = true;
                startIndices.push(index);   
            }
        }
        
        bool isWord = false;
        
        if (root -> children[s[0] - 'a'] != NULL)
            isWord = findWord(s.substr(1), root -> children[s[0] - 'a'], startIndices, index + 1, visited);
        
        return isWord;
    }
    
    bool wordBreak(string s, vector<string>& wordDict)
    {
        TrieNode* root = new TrieNode();
        
        for (auto& it : wordDict)
            insertWord(it, root);
        
        queue<int> startIndices;
        startIndices.push(0);
        unordered_map<int, bool> visited;
        
        while (!startIndices.empty())
        {
            int index = startIndices.front();
            startIndices.pop();
            
            if (findWord(s.substr(index), root, startIndices, index, visited))
                return true;
        }
        
        return false;
    }
};
