class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        int freqCount = -1;
        vector<int> freq(26), visited(26), ans;
        
        for (auto& it : s)
            freq[it - 'a']++;
        
        for (auto& it : s)
        {
            if (freqCount <= 0)
            {
                ans.push_back(1);
                visited[it - 'a'] = 1;
                freqCount += freqCount == -1 ? freq[it - 'a'] : freq[it - 'a'] - 1;
            }
            else
            {
                if (!visited[it - 'a'])
                    freqCount += freq[it - 'a'];
                
                freqCount--;
                visited[it - 'a'] = 1;
                ans.back()++;
            }
            
            freq[it - 'a']--;
        }
        
        return ans;
    }
};
