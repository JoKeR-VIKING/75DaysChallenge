class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        int pairs = 0;
        unordered_map<int, int> exists;
        
        if (k == 0)
        {
            for (int i=0;i<nums.size();i++)
            {
                if (exists.count(nums[i]) && exists[nums[i]] == 1)
                    pairs++;
                
                exists[nums[i]]++;
            }
            
            return pairs;
        }
        
        set<int> s(nums.begin(), nums.end());
        
        for (auto& it : s)
        {
            pairs += exists.count(it - k);
            exists[it] = true;
        }
        
        return pairs;
    }
};
