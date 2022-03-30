class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k)
    {
        int left = k - 1, right = cardPoints.size(), maxPoints = INT_MIN;
        vector<int> prefixSum = cardPoints;
        
        for (int i=1;i<prefixSum.size();i++)
            prefixSum[i] += prefixSum[i - 1];
        
        while (left > -2)
        {
            if (left == -1)
            {
                maxPoints = max(maxPoints, prefixSum.back() - (right == 0 ? 0 : prefixSum[right - 1]));
            }
            else if (right == cardPoints.size())
            {
                maxPoints = max(maxPoints, prefixSum[left]);
            }
            else
            {
                int sum = prefixSum[left];
                sum += prefixSum.back() - (right == 0 ? 0 : prefixSum[right - 1]);
                
                maxPoints = max(maxPoints, sum);
            }
            
            left--;
            right--;
        }
        
        return maxPoints;
    }
};
