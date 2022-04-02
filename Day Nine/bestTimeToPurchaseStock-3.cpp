class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        vector<int> left(prices.size()), right(prices.size());
        left[0] = right.back() = 0;
        int minPrice = prices[0], maxPrice = prices.back(), maxProfit;
        
        for (int i=1;i<prices.size();i++)
        {
            minPrice = min(minPrice, prices[i]);
            left[i] = max(left[i - 1], prices[i] - minPrice);
        }
        
        for (int i=prices.size() - 2;i>=0;i--)
        {
            maxPrice = max(maxPrice, prices[i+1]);
            right[i] = max(right[i + 1], maxPrice - prices[i]);
        }
        
        maxProfit = max(right[0], left.back());
        
        for (int i=1;i<prices.size();i++)
        {
            maxProfit = max(maxProfit, left[i - 1] + right[i]);
        }
        
        return maxProfit;
    }
};
