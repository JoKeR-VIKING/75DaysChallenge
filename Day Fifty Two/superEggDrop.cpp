class Solution {
public:
    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));
        
        for (int i=1;i<=n;i++)
            dp[1][i] = i;
        
        for (int i=1;i<=k;i++)
            dp[i][1] = 1;
        
        for (int i=2;i<=k;i++)
        {
            for (int j=2;j<=n;j++)
            {
                int maxAttempts = INT_MAX;
                pair<int, int> first = {i - 1, 0}, second = {i, j - 1};
                
                while (first.second < j)
                {
                    maxAttempts = min(maxAttempts, max(dp[first.first][first.second], dp[second.first][second.second]));
                    first.second++;
                    second.second--;
                }
                
                dp[i][j] = maxAttempts + 1;
            }
        }
        
        return dp.back().back();
    }
};
