class Solution {
public:
    int getSubarrayCount(vector<int>& nums, int k)
    {
        if (k == 0)
            return 0;
        
        int ans = 0, i = 0, diff = 0;
        unordered_map<int, int> freq;
        
        for (int j=0;j<nums.size();j++)
        {
            if (!freq[nums[j]])
                diff++;
            
            freq[nums[j]]++;
            
            if (diff <= k)
                ans += (j - i + 1);
            else
            {
                while (i < j && diff > k)
                {
                    freq[nums[i]]--;
                    if (freq[nums[i]] == 0)
                        diff--;
                    
                    i++;
                }
                
                ans += (j - i + 1);
            }
        }
        
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return getSubarrayCount(nums, k) - getSubarrayCount(nums, k - 1);
    }
};
