class Solution {
public:
    int characterReplacement(string s, int k)
    {
        vector<int> freq(26);
        int i = 0, ans = 0, maxFreq = 0;
        
        for (int j=0;j<s.size();j++)
        {
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);
            
            while (j - i - maxFreq + 1 > k)
                freq[s[i++] - 'A']--;
                
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};
