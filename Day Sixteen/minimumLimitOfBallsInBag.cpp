class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int start = 1, end = *(max_element(nums.begin(), nums.end())), ans;
        
        while (start <= end)
        {
            int mid = start + (end - start) / 2, k = 0;
            
            for (auto& it : nums)
                k += (it - 1) / mid;
            
            if (k <= maxOperations)
            {
                end = mid - 1;
                ans = mid;
            }
            else
                start = mid + 1;
        }
        
        return ans;
    }
};
