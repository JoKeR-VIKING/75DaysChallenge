class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int maxProfit = 0, priceDip = prices[0];
        
        for (int i=1;i<prices.size();i++)
        {
            priceDip = min(priceDip, prices[i]);
            maxProfit = max(maxProfit, prices[i] - priceDip);
        }
        
        return maxProfit;
    }
};
