class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        vector<int> indexMap(26);
        for (int i=0;i<order.length();i++)
            indexMap[order[i] - 'a'] = i;
        
        for (int i=1;i<words.size();i++)
        {
            int j = 0, k = 0;
            
            while (j < words[i].length() && k < words[i - 1].length())
            {
                if (words[i][j] != words[i - 1][k])
                {
                    if (indexMap[words[i][j] - 'a'] < indexMap[words[i - 1][k] - 'a'])
                        return false;
                    else
                        break;
                }
                
                j++;
                k++;
            }
            
            if (j == words[i].length() && k != words[i - 1].length())
                return false;
        }
        
        return true;
    }
};
