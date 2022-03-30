class Solution {
public:
    int jump(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), INT_MAX - 1);
        dp.back() = 0;
        
        for (int i=nums.size() - 2;i>=0;i--)
        {
            if (i + nums[i] >= nums.size() - 1)
            {
                dp[i] = 1;
            }
            else
            {
                for (int j=i+1;j<=i+nums[i];j++)
                    dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        
        return dp[0];
    }
};
