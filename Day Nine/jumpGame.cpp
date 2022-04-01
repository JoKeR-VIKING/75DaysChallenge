class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        vector<bool> dp(nums.size());
        dp.back() = true;
        int mostRecentEnd = nums.size() - 1;
        
        for (int i=nums.size()-2;i>=0;i--)
        {
            if (i + nums[i] >= mostRecentEnd)
            {
                mostRecentEnd = i;
                dp[i] = true;
            }
        }
        
        return dp[0];
    }
};
