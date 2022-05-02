class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> freq(26);
        for (int i=0;i<tasks.size();i++)
            freq[tasks[i] - 'A']++;
        
        sort(freq.begin(), freq.end());
        
        int maxFreq = freq.back() - 1;
        int idleSlots = maxFreq * n;
        
        for (int i=24;i>=0;i--)
            idleSlots -= min(freq[i], maxFreq);
        
        return idleSlots > 0 ? idleSlots + tasks.size() : tasks.size();
    }
};
