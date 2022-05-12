class Solution{   
public:
    bool isSubsetSum(vector<int>& arr, int sum)
    {
        vector<vector<bool>> dp(arr.size() + 1, vector<bool>(sum + 1));
        for (int i=0;i<=arr.size();i++)
            dp[i][0] = true;
    
        for (int i=1;i<=arr.size();i++)
        {
            for (int j=1;j<=sum;j++)
            {
                if (arr[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
    
        return dp.back().back();
    }
};
