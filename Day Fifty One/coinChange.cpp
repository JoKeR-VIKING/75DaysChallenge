class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (auto& it : coins)
        {
            for (int i=it;i<=amount;i++)
            {
                if (dp[i - it] == INT_MAX)
                    continue;
                
                dp[i] = min(dp[i], dp[i - it] + 1);
            }
        }
        
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};
