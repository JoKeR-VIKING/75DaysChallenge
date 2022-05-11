class Solution
{
public:
	int maxSumIS(int arr[], int n)  
	{
	    vector<int> dp(n);
	    
	    for (int i=0;i<n;i++)
	    {
	        dp[i] = arr[i];
	        
	        for (int j=i-1;j>=0;j--)
	        {
	            if (arr[i] > arr[j])
	            {
	                dp[i] = max(dp[i], dp[j] + arr[i]);
	            }
	        }
	    }
	    
	    return *max_element(dp.begin(), dp.end());
	} 
};
