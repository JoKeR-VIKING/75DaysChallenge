class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<vector<int>> freq(nums.size() + 1);
        unordered_map<int, int> um;
        vector<int> ans;
        
        for (auto& it : nums)
            um[it]++;
        
        for (auto& it : um)
            freq[it.second].push_back(it.first);
        
        for (int i=nums.size();i>=0 && ans.size() < k;i--)
        {
            for (auto& it : freq[i])
            {
                if (ans.size() >= k)
                    break;
                
                ans.push_back(it);
            }
        }
        
        return ans;
    }
};
