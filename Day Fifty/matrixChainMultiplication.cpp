class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N - 1, vector<int>(N - 1, INT_MAX));
        
        for (int g=0;g<dp.size();g++)
        {
            for (int i=0, j=g;j<dp.size();i++, j++)
            {
                if (g == 0)
                    dp[i][j] = 0;
                else if (g == 1)
                    dp[i][j] = arr[i] * arr[j] * arr[j + 1];
                else
                {
                    for (int k=i;k<j;k++)
                    {
                        int lc = dp[i][k];
                        int rc = dp[k + 1][j];
                        int mc = arr[i] * arr[k + 1] * arr[j + 1];
                        
                        dp[i][j] = min(dp[i][j], lc + rc + mc);
                    }
                }
            }
        }
        
        return dp[0][dp.size() - 1];
    }
};
