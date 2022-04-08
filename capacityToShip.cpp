class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int start = 1, end = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        
        while (start <= end)
        {
            int mid = start + (end - start) / 2, i = 0, k = 1, curr_weight = 0;
            
            for (;i<weights.size();i++)
            {
                if (weights[i] > mid)
                    break;
                
                if (weights[i] + curr_weight > mid)
                {
                    k++;
                    curr_weight = 0;
                }
                
                if (k > days)
                    break;
                
                curr_weight += weights[i];
            }
            
            if (i == weights.size())
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        return ans;
    }
};
