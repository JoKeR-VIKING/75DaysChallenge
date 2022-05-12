class Solution{
  public:
    int cutRod(int price[], int n)
    {
        vector<int> dp(n + 1);
        
        for (int i=1;i<=n;i++)
        {
            for (int j=i;j>0;j--)
            {
                dp[i] = max(dp[i], dp[i - j] + price[j - 1]);
            }
        }
        
        return dp[n];
    }
};
