class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        
        for (int i=0;i<n;i++)
        {
            for (int j=1;j<=W;j++)
            {
                dp[i + 1][j] = dp[i][j];
                
                if (j - wt[i] >= 0)
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - wt[i]] + val[i]);
            }
        }
        
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=W;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            
            cout<<"\n";
        }
        
        return dp[n][W];
    }
}
